add_executable(killclass src/main.cpp)

# Add precompiled headers
target_precompile_headers(killclass PRIVATE src/pch.h)

target_compile_features(killclass PRIVATE cxx_std_17)

target_link_libraries(killclass PRIVATE
        cmd::cmd
        wnd::wnd)


