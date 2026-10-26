/*
 * FUN_0040f304 at 0040f304
 * undefined __register FUN_0040f304(void)
 * Address ranges: 0040f304-0040f375
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f304(void)

{
  int iVar1;
  LPVOID pvVar2;
  undefined4 uVar3;
  
  pvVar2 = FUN_00406144();
  FUN_00402eac(*(int **)((int)pvVar2 + 8));
  pvVar2 = FUN_00406144();
  uVar3 = FUN_0040f798(*(undefined4 **)((int)pvVar2 + 0xc));
  pvVar2 = FUN_00406144();
  *(undefined4 *)((int)pvVar2 + 8) = uVar3;
  pvVar2 = FUN_00406144();
  iVar1 = *(int *)(*(int *)((int)pvVar2 + 0xc) + 8);
  pvVar2 = FUN_00406144();
  FUN_0040f550(*(int **)((int)pvVar2 + 0xc),iVar1 + -1);
  pvVar2 = FUN_00406144();
  if (*(int *)(*(int *)((int)pvVar2 + 0xc) + 8) == 0) {
    pvVar2 = FUN_00406144();
    FUN_0040bfec((undefined4 *)((int)pvVar2 + 0xc));
  }
  return;
}

