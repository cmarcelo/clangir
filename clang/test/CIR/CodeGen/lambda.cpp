// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fenable-clangir -emit-cir %s -o %t.cir
// RUN: FileCheck --input-file=%t.cir %s

void fn() {
  auto a = [](){};
}

//      CHECK: !22class2Eanon22 = !cir.struct<"class.anon", i8>
// CHECK-NEXT: module
// CHECK-NEXT:   cir.func @_Z2fnv()
// CHECK-NEXT:     %0 = cir.alloca !22class2Eanon22, cir.ptr <!22class2Eanon22>, ["a", uninitialized]
