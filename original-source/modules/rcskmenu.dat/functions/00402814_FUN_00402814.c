/*
 * FUN_00402814 at 00402814
 * undefined4 __register FUN_00402814(void)
 * Address ranges: 00402814-00402829
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402814(void)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  
  pvVar2 = FUN_00406144();
  uVar1 = *(undefined4 *)((int)pvVar2 + 4);
  *(undefined4 *)((int)pvVar2 + 4) = 0;
  return uVar1;
}

