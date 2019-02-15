/*
    rstanemax is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    rstanemax is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with rstanemax.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.18.0

#include <stan/model/model_header.hpp>

namespace model_mod_emax_e0_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_mod_emax_e0");
    reader.add_event(45, 43, "end", "model_mod_emax_e0");
    return reader;
}

#include <meta_header.hpp>
 class model_mod_emax_e0 : public prob_grad {
private:
    int N;
    vector_d exposure;
    vector_d response;
    int hill_fix;
    int e0_fix;
    double hill_fix_value;
    double e0_fix_value;
public:
    model_mod_emax_e0(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_mod_emax_e0(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_mod_emax_e0_namespace::model_mod_emax_e0";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            current_statement_begin__ = 3;
            validate_non_negative_index("exposure", "N", N);
            context__.validate_dims("data initialization", "exposure", "vector_d", context__.to_vec(N));
            validate_non_negative_index("exposure", "N", N);
            exposure = vector_d(static_cast<Eigen::VectorXd::Index>(N));
            vals_r__ = context__.vals_r("exposure");
            pos__ = 0;
            size_t exposure_i_vec_lim__ = N;
            for (size_t i_vec__ = 0; i_vec__ < exposure_i_vec_lim__; ++i_vec__) {
                exposure[i_vec__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 4;
            validate_non_negative_index("response", "N", N);
            context__.validate_dims("data initialization", "response", "vector_d", context__.to_vec(N));
            validate_non_negative_index("response", "N", N);
            response = vector_d(static_cast<Eigen::VectorXd::Index>(N));
            vals_r__ = context__.vals_r("response");
            pos__ = 0;
            size_t response_i_vec_lim__ = N;
            for (size_t i_vec__ = 0; i_vec__ < response_i_vec_lim__; ++i_vec__) {
                response[i_vec__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 6;
            context__.validate_dims("data initialization", "hill_fix", "int", context__.to_vec());
            hill_fix = int(0);
            vals_i__ = context__.vals_i("hill_fix");
            pos__ = 0;
            hill_fix = vals_i__[pos__++];
            current_statement_begin__ = 7;
            context__.validate_dims("data initialization", "e0_fix", "int", context__.to_vec());
            e0_fix = int(0);
            vals_i__ = context__.vals_i("e0_fix");
            pos__ = 0;
            e0_fix = vals_i__[pos__++];
            current_statement_begin__ = 8;
            context__.validate_dims("data initialization", "hill_fix_value", "double", context__.to_vec());
            hill_fix_value = double(0);
            vals_r__ = context__.vals_r("hill_fix_value");
            pos__ = 0;
            hill_fix_value = vals_r__[pos__++];
            current_statement_begin__ = 9;
            context__.validate_dims("data initialization", "e0_fix_value", "double", context__.to_vec());
            e0_fix_value = double(0);
            vals_r__ = context__.vals_r("e0_fix_value");
            pos__ = 0;
            e0_fix_value = vals_r__[pos__++];

            // validate, data variables
            current_statement_begin__ = 2;
            check_greater_or_equal(function__,"N",N,1);
            current_statement_begin__ = 3;
            check_greater_or_equal(function__,"exposure",exposure,0);
            current_statement_begin__ = 4;
            current_statement_begin__ = 6;
            check_greater_or_equal(function__,"hill_fix",hill_fix,0);
            check_less_or_equal(function__,"hill_fix",hill_fix,1);
            current_statement_begin__ = 7;
            check_greater_or_equal(function__,"e0_fix",e0_fix,0);
            check_less_or_equal(function__,"e0_fix",e0_fix,1);
            current_statement_begin__ = 8;
            check_greater_or_equal(function__,"hill_fix_value",hill_fix_value,0);
            current_statement_begin__ = 9;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 14;
            ++num_params_r__;
            current_statement_begin__ = 15;
            ++num_params_r__;
            current_statement_begin__ = 16;
            ++num_params_r__;
            current_statement_begin__ = 17;
            ++num_params_r__;
            current_statement_begin__ = 19;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_mod_emax_e0() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("emax")))
            throw std::runtime_error("variable emax missing");
        vals_r__ = context__.vals_r("emax");
        pos__ = 0U;
        context__.validate_dims("initialization", "emax", "double", context__.to_vec());
        double emax(0);
        emax = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(emax);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable emax: ") + e.what());
        }

        if (!(context__.contains_r("ec50")))
            throw std::runtime_error("variable ec50 missing");
        vals_r__ = context__.vals_r("ec50");
        pos__ = 0U;
        context__.validate_dims("initialization", "ec50", "double", context__.to_vec());
        double ec50(0);
        ec50 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,ec50);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable ec50: ") + e.what());
        }

        if (!(context__.contains_r("e0")))
            throw std::runtime_error("variable e0 missing");
        vals_r__ = context__.vals_r("e0");
        pos__ = 0U;
        context__.validate_dims("initialization", "e0", "double", context__.to_vec());
        double e0(0);
        e0 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(e0);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable e0: ") + e.what());
        }

        if (!(context__.contains_r("gamma_par")))
            throw std::runtime_error("variable gamma_par missing");
        vals_r__ = context__.vals_r("gamma_par");
        pos__ = 0U;
        context__.validate_dims("initialization", "gamma_par", "double", context__.to_vec());
        double gamma_par(0);
        gamma_par = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,gamma_par);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable gamma_par: ") + e.what());
        }

        if (!(context__.contains_r("sigma")))
            throw std::runtime_error("variable sigma missing");
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma", "double", context__.to_vec());
        double sigma(0);
        sigma = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);

            local_scalar_t__ emax;
            (void) emax;  // dummy to suppress unused var warning
            if (jacobian__)
                emax = in__.scalar_constrain(lp__);
            else
                emax = in__.scalar_constrain();

            local_scalar_t__ ec50;
            (void) ec50;  // dummy to suppress unused var warning
            if (jacobian__)
                ec50 = in__.scalar_lb_constrain(0,lp__);
            else
                ec50 = in__.scalar_lb_constrain(0);

            local_scalar_t__ e0;
            (void) e0;  // dummy to suppress unused var warning
            if (jacobian__)
                e0 = in__.scalar_constrain(lp__);
            else
                e0 = in__.scalar_constrain();

            local_scalar_t__ gamma_par;
            (void) gamma_par;  // dummy to suppress unused var warning
            if (jacobian__)
                gamma_par = in__.scalar_lb_constrain(0,lp__);
            else
                gamma_par = in__.scalar_lb_constrain(0);

            local_scalar_t__ sigma;
            (void) sigma;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma = in__.scalar_lb_constrain(0,lp__);
            else
                sigma = in__.scalar_lb_constrain(0);


            // transformed parameters
            current_statement_begin__ = 23;
            validate_non_negative_index("respHat", "N", N);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  respHat(static_cast<Eigen::VectorXd::Index>(N));
            (void) respHat;  // dummy to suppress unused var warning

            stan::math::initialize(respHat, DUMMY_VAR__);
            stan::math::fill(respHat,DUMMY_VAR__);
            current_statement_begin__ = 24;
            validate_non_negative_index("exposure_exp", "N", N);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  exposure_exp(static_cast<Eigen::VectorXd::Index>(N));
            (void) exposure_exp;  // dummy to suppress unused var warning

            stan::math::initialize(exposure_exp, DUMMY_VAR__);
            stan::math::fill(exposure_exp,DUMMY_VAR__);
            current_statement_begin__ = 26;
            local_scalar_t__ gamma;
            (void) gamma;  // dummy to suppress unused var warning

            stan::math::initialize(gamma, DUMMY_VAR__);
            stan::math::fill(gamma,DUMMY_VAR__);


            current_statement_begin__ = 28;
            stan::math::assign(gamma, (hill_fix ? stan::math::promote_scalar<local_scalar_t__>(hill_fix_value) : stan::math::promote_scalar<local_scalar_t__>(gamma_par) ));
            current_statement_begin__ = 30;
            for (int i = 1; i <= N; ++i) {
                current_statement_begin__ = 30;
                stan::model::assign(exposure_exp, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            pow(get_base1(exposure,i,"exposure",1),gamma), 
                            "assigning variable exposure_exp");
            }
            current_statement_begin__ = 32;
            stan::math::assign(respHat, add(e0,elt_divide(multiply(emax,exposure_exp),add(pow(ec50,gamma),exposure_exp))));

            // validate transformed parameters
            for (int i0__ = 0; i0__ < N; ++i0__) {
                if (stan::math::is_uninitialized(respHat(i0__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: respHat" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }
            for (int i0__ = 0; i0__ < N; ++i0__) {
                if (stan::math::is_uninitialized(exposure_exp(i0__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: exposure_exp" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }
            if (stan::math::is_uninitialized(gamma)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: gamma";
                throw std::runtime_error(msg__.str());
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 23;
            current_statement_begin__ = 24;
            current_statement_begin__ = 26;

            // model body

            current_statement_begin__ = 36;
            lp_accum__.add(normal_log<propto__>(response, respHat, sigma));
            current_statement_begin__ = 37;
            lp_accum__.add(normal_log<propto__>(e0, 0, 10));
            current_statement_begin__ = 38;
            lp_accum__.add(normal_log<propto__>(ec50, 0, 1000));
            current_statement_begin__ = 41;
            lp_accum__.add(cauchy_log<propto__>(sigma, 0, 10));

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("emax");
        names__.push_back("ec50");
        names__.push_back("e0");
        names__.push_back("gamma_par");
        names__.push_back("sigma");
        names__.push_back("respHat");
        names__.push_back("exposure_exp");
        names__.push_back("gamma");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);
        static const char* function__ = "model_mod_emax_e0_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double emax = in__.scalar_constrain();
        double ec50 = in__.scalar_lb_constrain(0);
        double e0 = in__.scalar_constrain();
        double gamma_par = in__.scalar_lb_constrain(0);
        double sigma = in__.scalar_lb_constrain(0);
        vars__.push_back(emax);
        vars__.push_back(ec50);
        vars__.push_back(e0);
        vars__.push_back(gamma_par);
        vars__.push_back(sigma);

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            current_statement_begin__ = 23;
            validate_non_negative_index("respHat", "N", N);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  respHat(static_cast<Eigen::VectorXd::Index>(N));
            (void) respHat;  // dummy to suppress unused var warning

            stan::math::initialize(respHat, DUMMY_VAR__);
            stan::math::fill(respHat,DUMMY_VAR__);
            current_statement_begin__ = 24;
            validate_non_negative_index("exposure_exp", "N", N);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  exposure_exp(static_cast<Eigen::VectorXd::Index>(N));
            (void) exposure_exp;  // dummy to suppress unused var warning

            stan::math::initialize(exposure_exp, DUMMY_VAR__);
            stan::math::fill(exposure_exp,DUMMY_VAR__);
            current_statement_begin__ = 26;
            local_scalar_t__ gamma;
            (void) gamma;  // dummy to suppress unused var warning

            stan::math::initialize(gamma, DUMMY_VAR__);
            stan::math::fill(gamma,DUMMY_VAR__);


            current_statement_begin__ = 28;
            stan::math::assign(gamma, (hill_fix ? stan::math::promote_scalar<local_scalar_t__>(hill_fix_value) : stan::math::promote_scalar<local_scalar_t__>(gamma_par) ));
            current_statement_begin__ = 30;
            for (int i = 1; i <= N; ++i) {
                current_statement_begin__ = 30;
                stan::model::assign(exposure_exp, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            pow(get_base1(exposure,i,"exposure",1),gamma), 
                            "assigning variable exposure_exp");
            }
            current_statement_begin__ = 32;
            stan::math::assign(respHat, add(e0,elt_divide(multiply(emax,exposure_exp),add(pow(ec50,gamma),exposure_exp))));

            // validate transformed parameters
            current_statement_begin__ = 23;
            current_statement_begin__ = 24;
            current_statement_begin__ = 26;

            // write transformed parameters
            if (include_tparams__) {
            for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(respHat[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(exposure_exp[k_0__]);
            }
        vars__.push_back(gamma);
            }
            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_mod_emax_e0";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "emax";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "ec50";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "e0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "gamma_par";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "respHat" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "exposure_exp" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            param_name_stream__.str(std::string());
            param_name_stream__ << "gamma";
            param_names__.push_back(param_name_stream__.str());
        }


        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "emax";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "ec50";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "e0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "gamma_par";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "respHat" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "exposure_exp" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
            param_name_stream__.str(std::string());
            param_name_stream__ << "gamma";
            param_names__.push_back(param_name_stream__.str());
        }


        if (!include_gqs__) return;
    }

}; // model

}

typedef model_mod_emax_e0_namespace::model_mod_emax_e0 stan_model;


#endif
