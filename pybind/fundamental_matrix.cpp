#include "pybind/fundamental_matrix.h"

#include "estimator/fundamental_matrix.h"

void pybind_fundamental_matrix(py::module &m) {
    py::module m_submodule = m.def_submodule("fundamental_matrix");
    py::class_<FundamentalMatrixSevenPointEstimator> fundalmental_seven(m_submodule, "FundamentalMatrixSevenPointEstimator");
    py::detail::bind_default_constructor<FundamentalMatrixSevenPointEstimator>(fundalmental_seven);
    py::detail::bind_copy_functions<FundamentalMatrixSevenPointEstimator>(fundalmental_seven);
    fundalmental_seven
        .def_static("Estimate", &FundamentalMatrixSevenPointEstimator::Estimate)
        .def_static("Residuals", &FundamentalMatrixSevenPointEstimator::Residuals);
    py::class_<FundamentalMatrixEightPointEstimator> fundamental_eight(m_submodule, "FundamentalMatrixEightPointEstimator");
    py::detail::bind_default_constructor<FundamentalMatrixEightPointEstimator>(fundamental_eight);
    py::detail::bind_copy_functions<FundamentalMatrixEightPointEstimator>(fundamental_eight);
    fundamental_eight
        .def_static("Estimate", &FundamentalMatrixEightPointEstimator::Estimate)
        .def_static("Residuals", &FundamentalMatrixEightPointEstimator::Residuals);
}