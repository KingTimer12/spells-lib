# Diretório de testes unitários
cmake_minimum_required(VERSION 3.15)

# Baixar e adicionar Google Test
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1 # Use a versão mais recente estável
)

# Evitar que o Google Test execute a instalação automática
set(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)

FetchContent_MakeAvailable(googletest)

# Criar um executável para os testes
add_executable(spellslib_tests
    test_main.cpp
    test_gnar.cpp
)

# Linkar o Google Test e a biblioteca principal ao executável de teste
target_link_libraries(spellslib_tests
    PRIVATE
        GTest::gtest
        GTest::gtest_main
        spellslib
)

# Configurar CMake para executar os testes automaticamente
include(GoogleTest)
gtest_discover_tests(spellslib_tests)