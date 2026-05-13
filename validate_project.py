#!/usr/bin/env python3
import os
import subprocess
from pathlib import Path

project_root = Path('c:\\Users\\Milson Yuji Aoki\\Dev_yuji\\proj-03-ultimate-runtime')
os.chdir(project_root)

print("=" * 70)
print("🔍 VALIDAÇÃO COMPLETA DO PROJETO")
print("=" * 70)

# 1. Validar estrutura de diretórios
print("\n✓ Validando estrutura de diretórios...")
required_dirs = [
    'foundation', 'libraries', 'monetization',
    'runtime/libft', 'runtime/libds', 'runtime/libai',
    'runtime/core', 'runtime/vm', 'runtime/services',
    'runtime/foundation', 'runtime/platform'
]

missing_dirs = []
for d in required_dirs:
    path = project_root / d
    if not path.exists():
        missing_dirs.append(d)
    else:
        print(f"  ✓ {d}")

if missing_dirs:
    print(f"\n❌ Diretórios faltando: {missing_dirs}")
else:
    print("\n✓ Todos os diretórios obrigatórios existem!")

# 2. Validar arquivos críticos
print("\n✓ Validando arquivos críticos...")
critical_files = [
    'CMakeLists.txt', 'CMakePresets.json', 'Makefile',
    'README.md', 'LICENSE', 'ARCHITECTURE.md'
]

missing_files = []
for f in critical_files:
    path = project_root / f
    if not path.exists():
        missing_files.append(f)
    else:
        print(f"  ✓ {f}")

if missing_files:
    print(f"\n❌ Arquivos faltando: {missing_files}")
else:
    print("\n✓ Todos os arquivos críticos existem!")

# 3. Validar libft
print("\n✓ Validando libft...")
libft_root = project_root / 'runtime/libft'
libft_files = [
    'Makefile', 'CMakeLists.txt', 'README.md', 'include'
]

for f in libft_files:
    path = libft_root / f
    if path.exists():
        print(f"  ✓ libft/{f}")
    else:
        print(f"  ❌ libft/{f} FALTANDO")

# 4. Contar arquivos .c em libft
c_files = list(libft_root.glob('src/**/*.c'))
print(f"\n  ✓ {len(c_files)} arquivos .c encontrados em libft/src/")

# 5. Listar estrutura alto nível
print("\n✓ Estrutura de diretórios raiz:")
for item in sorted(project_root.iterdir()):
    if item.is_dir() and not item.name.startswith('.'):
        sub_count = len(list(item.glob('*')))
        print(f"  ├─ {item.name:30} ({sub_count:3} itens)")
    elif item.is_file():
        print(f"  ├─ {item.name:30}")

print("\n" + "=" * 70)
print("✅ VALIDAÇÃO CONCLUÍDA")
print("=" * 70)
