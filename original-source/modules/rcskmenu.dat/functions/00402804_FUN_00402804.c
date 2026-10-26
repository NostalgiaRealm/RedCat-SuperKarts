/*
 * FUN_00402804 at 00402804
 * undefined __register FUN_00402804(undefined4 param_1)
 * Address ranges: 00402804-00402810
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402804(undefined4 param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = FUN_00406144();
  *(undefined4 *)((int)pvVar1 + 4) = param_1;
  return;
}

