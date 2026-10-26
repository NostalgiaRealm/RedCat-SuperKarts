/*
 * FUN_00442f94 at 00442f94
 * undefined4 __register FUN_00442f94(int param_1, undefined4 param_2, undefined4 param_3, char param_4)
 * Address ranges: 00442f94-00443026
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00442f94(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar3;
  undefined1 *puVar4;
  
  if (((param_4 != '\0') && (*(int *)(param_1 + 0x180) != 0)) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 0x180) + 8) + -1, -1 < iVar3)) {
    do {
      puVar4 = &stack0xfffffffc;
      piVar2 = (int *)FUN_0040f6b0(*(undefined4 **)(param_1 + 0x180),iVar3);
      cVar1 = FUN_00442edc(piVar2,extraout_EDX,extraout_ECX,(int)puVar4);
      if (cVar1 != '\0') break;
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
  }
  if ((*(int *)(param_1 + 0x134) != 0) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 0x134) + 8) + -1, -1 < iVar3)) {
    do {
      puVar4 = &stack0xfffffffc;
      piVar2 = (int *)FUN_0040f6b0(*(undefined4 **)(param_1 + 0x134),iVar3);
      cVar1 = FUN_00442edc(piVar2,extraout_EDX_00,extraout_ECX_00,(int)puVar4);
      if (cVar1 != '\0') {
        return 0;
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
  }
  return 0;
}

