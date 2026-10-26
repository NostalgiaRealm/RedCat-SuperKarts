/*
 * FUN_00451610 at 00451610
 * undefined4 __register FUN_00451610(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00451610-0045165a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00451610(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  if (0 < *(int *)(param_1 + 0x43c)) {
    if (*(char *)(param_1 + 0x14) != '\0') {
      *(undefined1 *)(param_1 + 0x14) = 0;
      piVar1 = FUN_004507d8(param_1,param_2,param_3);
      uVar2 = FUN_00450794((int)piVar1,(int *)(param_1 + 0x438));
      piVar1 = FUN_004507d8(uVar2,extraout_EDX,extraout_ECX);
      iVar3 = FUN_00450678((int)piVar1,(byte *)(param_1 + 0x15),*(int *)(param_1 + 0x43c));
      *(int *)(param_1 + 0x438) = iVar3;
    }
    return *(undefined4 *)(param_1 + 0x438);
  }
  return 0;
}

