// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.idl

#include "Runnable.hpp"  // my header

namespace djinni_generated {

Runnable::Runnable() : ::djinni::JniInterface<::Runnable, Runnable>("Runnable$CppProxy") {}

Runnable::~Runnable() = default;


CJNIEXPORT void JNICALL Java_Runnable_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::Runnable>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_Runnable_00024CppProxy_native_1run(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::Runnable>(nativeRef);
        ref->run();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated