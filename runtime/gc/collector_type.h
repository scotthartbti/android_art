/*
 * Copyright (C) 2013 The Android Open Source Project
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

#ifndef ART_RUNTIME_GC_COLLECTOR_TYPE_H_
#define ART_RUNTIME_GC_COLLECTOR_TYPE_H_

#include <iosfwd>

namespace art {
namespace gc {

// Which types of collections are able to be performed.
enum CollectorType {
  // No collector selected.
  kCollectorTypeNone,
  // Non concurrent mark-sweep.
  kCollectorTypeMS,
  // Concurrent mark-sweep.
  kCollectorTypeCMS,
  // Semi-space / mark-sweep hybrid, enables compaction.
  kCollectorTypeSS,
  // A generational variant of kCollectorTypeSS.
  kCollectorTypeGSS,
  // Mark compact collector.
  kCollectorTypeMC,
  // Heap trimming collector, doesn't do any actual collecting.
  kCollectorTypeHeapTrim,
  // A (mostly) concurrent copying collector.
  kCollectorTypeCC,
  // Instrumentation critical section fake collector.
  kCollectorTypeInstrumentation,
  // Fake collector for adding or removing application image spaces.
  kCollectorTypeAddRemoveAppImageSpace,
  // A homogeneous space compaction collector used in background transition
  // when both foreground and background collector are CMS.
  kCollectorTypeHomogeneousSpaceCompact,
  // Class linker fake collector.
  kCollectorTypeClassLinker,
};
std::ostream& operator<<(std::ostream& os, const CollectorType& collector_type);

static constexpr CollectorType kCollectorTypeDefault =
#if ART_DEFAULT_GC_TYPE_IS_CMS
    kCollectorTypeCMS
#elif ART_DEFAULT_GC_TYPE_IS_SS
    kCollectorTypeSS
#elif ART_DEFAULT_GC_TYPE_IS_GSS
    kCollectorTypeGSS
#else
    kCollectorTypeCMS
#error "ART default GC type must be set"
#endif
    ;  // NOLINT [whitespace/semicolon] [5]

}  // namespace gc
}  // namespace art

#endif  // ART_RUNTIME_GC_COLLECTOR_TYPE_H_
