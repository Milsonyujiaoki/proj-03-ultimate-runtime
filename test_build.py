#!/usr/bin/env python3
import os
import subprocess
from pathlib import Path

project_root = Path('c:\\Users\\Milson Yuji Aoki\\Dev_yuji\\proj-03-ultimate-runtime')
os.chdir(project_root)

print("=" * 70)
print("🧪 TESTE DE BUILD DO PROJETO")
print("=" * 70)

# 1. Teste Makefile do libft
print("\n1️⃣  Testando Makefile do libft...")
os.chdir(project_root / 'runtime/libft')
result = subprocess.run(['make', 'clean'], capture_output=True, text=True, shell=True)
print(f"  make clean: {'✓' if result.returncode == 0 else '❌'}")

result = subprocess.run(['make'], capture_output=True, text=True, shell=True, timeout=60)
if result.returncode == 0:
    print(f"  make: ✓")
    # Verificar se libft.a foi criado
    if (Path('build/libft.a')).exists():
        print(f"  ✓ libft.a criado com sucesso")
    else:
        print(f"  ⚠ libft.a não encontrado em build/")
else:
    print(f"  ❌ make falhou")
    if result.stderr:
        print(f"  Erro: {result.stderr[:500]}")

# 2. Teste CMakeLists.txt do libft
print("\n2️⃣  Testando CMakeLists.txt do libft...")
os.chdir(project_root)

build_dir = project_root / 'build_test'
build_dir.mkdir(exist_ok=True)
os.chdir(build_dir)

# Limpar build anterior
subprocess.run(['cmake', '--build', '.', '--target', 'clean'], capture_output=True, shell=True)

# Configurar
result = subprocess.run(
    ['cmake', '-DCMAKE_BUILD_TYPE=Release', '-DENABLE_TESTING=ON', '..'],
    capture_output=True, text=True, shell=True, timeout=60
)

if result.returncode == 0:
    print(f"  cmake configure: ✓")
    
    # Fazer build
    result = subprocess.run(
        ['cmake', '--build', '.', '--config', 'Release', '--target', 'libft'],
        capture_output=True, text=True, shell=True, timeout=120
    )
    
    if result.returncode == 0:
        print(f"  cmake build libft: ✓")
    else:
        print(f"  ❌ cmake build libft falhou")
        if result.stderr:
            print(f"  Erro: {result.stderr[:1000]}")
else:
    print(f"  ❌ cmake configure falhou")
    if result.stderr:
        print(f"  Erro: {result.stderr[:1000]}")

# 3. Teste do projeto completo
print("\n3️⃣  Testando projeto completo...")
os.chdir(project_root)

build_dir2 = project_root / 'build_full'
build_dir2.mkdir(exist_ok=True)
os.chdir(build_dir2)

result = subprocess.run(
    ['cmake', '-DCMAKE_BUILD_TYPE=Debug', '-DUR_BUILD_TESTS=OFF', '..'],
    capture_output=True, text=True, shell=True, timeout=60
)

if result.returncode == 0:
    print(f"  cmake configure (full): ✓")
else:
    print(f"  ❌ cmake configure (full) falhou")
    if result.stderr:
        print(f"  Erro: {result.stderr[:1000]}")

print("\n" + "=" * 70)
print("✅ TESTES DE BUILD CONCLUÍDOS")
print("=" * 70)
