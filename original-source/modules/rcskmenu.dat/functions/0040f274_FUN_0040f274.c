/*
 * FUN_0040f274 at 0040f274
 * undefined __register FUN_0040f274(void)
 * Address ranges: 0040f274-0040f2d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f274(void)

{
  int iVar1;
  LPVOID pvVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  
  pvVar2 = FUN_00406144();
  if (*(int *)((int)pvVar2 + 0xc) == 0) {
    uVar3 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX);
    pvVar2 = FUN_00406144();
    *(undefined4 *)((int)pvVar2 + 0xc) = uVar3;
  }
  pvVar2 = FUN_00406144();
  iVar1 = *(int *)((int)pvVar2 + 8);
  pvVar2 = FUN_00406144();
  FUN_0040f504(*(int **)((int)pvVar2 + 0xc),iVar1);
  uVar3 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_00);
  pvVar2 = FUN_00406144();
  *(undefined4 *)((int)pvVar2 + 8) = uVar3;
  return;
}

