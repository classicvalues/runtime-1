/*
 * Copyright 2020 The TensorFlow Runtime Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Forward-declares HIP API types used in platform-agnostic wrapper headers.
#ifndef TFRT_GPU_WRAPPER_HIP_FORWARDS_H_
#define TFRT_GPU_WRAPPER_HIP_FORWARDS_H_

#include <cstddef>

// Forward declaration of HIP types.
using hipDevice_t = int;
using hipCtx_t = struct ihipCtx_t *;
using hipModule_t = struct ihipModule_t *;
using hipStream_t = struct ihipStream_t *;
using hipEvent_t = struct ihipEvent_t *;
using hipFunction_t = struct ihipModuleSymbol_t *;

// Forward declaration of MIOpen types.
using miopenHandle_t = struct miopenHandle *;
using miopenAcceleratorQueue_t = hipStream_t;
using miopenFusionOpDescriptor_t = struct miopenFusionOpDescriptor *;
using miopenTensorDescriptor_t = struct miopenTensorDescriptor *;
using miopenConvolutionDescriptor_t = struct miopenConvolutionDescriptor *;
using miopenPoolingDescriptor_t = struct miopenPoolingDescriptor *;
using miopenLRNDescriptor_t = struct miopenLRNDescriptor *;
using miopenActivationDescriptor_t = struct miopenActivationDescriptor *;
using miopenRNNDescriptor_t = struct miopenRNNDescriptor *;
using miopenCTCLossDescriptor_t = struct miopenCTCLossDescriptor *;
using miopenDropoutDescriptor_t = struct miopenDropoutDescriptor *;
using miopenFusionPlanDescriptor_t = struct miopenFusionPlanDescriptor *;
using miopenOperatorDescriptor_t = struct miopenOperatorDescriptor *;
using miopenOperatorArgs_t = struct miopenOperatorArgs *;
using miopenAllocatorFunction = void *(*)(void *context, size_t sizeBytes);
using miopenDeallocatorFunction = void *(*)(void *context, void *memory);
struct miopenConvAlgoPerf_t;
struct miopenConvSolution_t;

// Forward declaration of rocFFT types.
using rocfft_plan = struct rocfft_plan_t *;
using rocfft_plan_description = struct rocfft_plan_description_t *;
using rocfft_execution_info = struct rocfft_execution_info_t *;

// Forward declaration of rocBLAS types.
using rocblas_handle = struct _rocblas_handle *;

// Forward declaration of rocSOLVER types.
using rocsolver_handle = rocblas_handle;

namespace llvm {
// Define pointer traits for incomplete types.
template <typename>
struct PointerLikeTypeTraits;
template <>
struct PointerLikeTypeTraits<rocfft_execution_info> {
  static void *getAsVoidPointer(rocfft_execution_info ptr) { return ptr; }
  static rocfft_execution_info getFromVoidPointer(void *ptr) {
    return static_cast<rocfft_execution_info>(ptr);
  }
  // NOLINTNEXTLINE(readability-identifier-naming)
  static constexpr int NumLowBitsAvailable = 2;
};
}  // namespace llvm

#endif  // TFRT_GPU_WRAPPER_HIP_FORWARDS_H_
