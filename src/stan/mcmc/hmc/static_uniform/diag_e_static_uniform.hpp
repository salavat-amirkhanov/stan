#ifndef STAN_MCMC_HMC_STATIC_UNIFORM_DIAG_E_STATIC_UNIFORM_HPP
#define STAN_MCMC_HMC_STATIC_UNIFORM_DIAG_E_STATIC_UNIFORM_HPP

#include <stan/mcmc/hmc/static_uniform/base_static_uniform.hpp>
#include <stan/mcmc/hmc/hamiltonians/diag_e_point.hpp>
#include <stan/mcmc/hmc/hamiltonians/diag_e_metric.hpp>
#include <stan/mcmc/hmc/integrators/expl_leapfrog.hpp>

namespace stan {

  namespace mcmc {

    // Hamiltonian Monte Carlo on a
    // Euclidean manifold with diagonal metric
    // and static integration time
    template <typename M, class BaseRNG>
    class diag_e_static_uniform
      : public base_static_uniform<M, diag_e_point, diag_e_metric,
                               expl_leapfrog, BaseRNG> {
    public:
      diag_e_static_uniform(M &m, BaseRNG& rng,
                        std::ostream* o, std::ostream* e)
        : base_static_uniform<M, diag_e_point, diag_e_metric,
                          expl_leapfrog, BaseRNG>(m, rng, o, e) {
        this->name_ = "Static HMC with a diagonal Euclidean metric";
      }
    };

  }  // mcmc

}  // stan

#endif