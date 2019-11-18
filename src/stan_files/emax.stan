data{
  int<lower = 1> N;
  vector<lower = 0>[N] exposure;
  vector[N] response;

  // Covariates
  int<lower = 1> covemax[N];
  int<lower = 1> covec50[N];
  int<lower = 1> cove0[N];
  int<lower = 1> n_covlev_emax;
  int<lower = 1> n_covlev_ec50;
  int<lower = 1> n_covlev_e0;

  // Fixed parameters
  int<lower=0,upper=1> gamma_fix_flg;
  int<lower=0,upper=1> e0_fix_flg;
  real<lower=0> gamma_fix_value;
  real e0_fix_value;

  // priors
  //// mu
  real prior_emax_mu;
  real<lower=0> prior_ec50_mu;
  real<lower=0> prior_gamma_mu;
  real prior_e0_mu;
  real<lower=0> prior_sigma_mu;
  //// sigma
  real<lower=0> prior_emax_sig;
  real<lower=0> prior_ec50_sig;
  real<lower=0> prior_gamma_sig;
  real<lower=0> prior_e0_sig;
  real<lower=0> prior_sigma_sig;
}

parameters{
  vector[n_covlev_emax] emax;
  vector<lower = 0>[n_covlev_ec50] ec50;
  // vector[n_covlev_e0] e0_par[1-e0_fix_flg];
  real e0_par[n_covlev_e0, 1-e0_fix_flg];
  real<lower = 0> gamma_par[1-gamma_fix_flg];

  real<lower = 0> sigma;
}

transformed parameters{
  vector[N] respHat;
  vector[N] exposure_exp;

  real gamma;
  vector[n_covlev_e0] e0;

  vector[N] emaxvec;
  vector[N] ec50vec;
  vector[N] ec50vec_exp;
  vector[N] e0vec;

  // Prep gamma and e0 - fixed or not fixed
  gamma = gamma_fix_flg ? gamma_fix_value : gamma_par[1];
  for(i in 1:n_covlev_e0) e0[i] = e0_fix_flg ? e0_fix_value : e0_par[i, 1];

  // Prep param for each individual
  emaxvec = emax[covemax];
  ec50vec = ec50[covec50];
  e0vec   = e0[cove0];

  for(i in 1:N) {
    exposure_exp[i] = exposure[i]^gamma;
    ec50vec_exp[i]  = ec50vec[i]^gamma;
  }

  respHat = e0vec + emaxvec .* exposure_exp ./ (ec50vec_exp + exposure_exp);
}

model{
  response ~ normal(respHat, sigma);

  emax       ~ normal(prior_emax_mu,  prior_emax_sig);
  ec50       ~ normal(prior_ec50_mu,  prior_ec50_sig);
  gamma_par  ~ normal(prior_gamma_mu, prior_gamma_sig);
  sigma      ~ normal(prior_sigma_mu, prior_sigma_sig);
  for(i in 1:n_covlev_e0) {
    e0_par[i] ~ normal(prior_e0_mu,    prior_e0_sig);
  }
}

generated quantities {
  vector[N] log_lik;
  for (n in 1:N) log_lik[n] = normal_lpdf(response[n]| respHat[n], sigma);
}
