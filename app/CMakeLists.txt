add_executable(killprocess src/main.cpp)

# Add precompiled headers
#target_precompile_headers(killprocess PRIVATE src/pch.h)

target_compile_features(killprocess PRIVATE cxx_std_17)

target_link_libraries(killprocess PRIVATE
        cmd::cmd
        wnd::wnd)


