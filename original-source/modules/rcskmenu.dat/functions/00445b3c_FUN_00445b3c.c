/*
 * FUN_00445b3c at 00445b3c
 * undefined __register FUN_00445b3c(int * param_1, int param_2, undefined4 param_3, char param_4, char param_5)
 * Address ranges: 00445b3c-00445c31
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445b3c(int *param_1,int param_2,undefined4 param_3,char param_4,char param_5)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  int local_14;
  int *local_10;
  
  local_10 = (int *)0x0;
  puStack_28 = (undefined1 *)0x445b5e;
  piVar2 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
  puStack_2c = &LAB_00445c32;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  FUN_00403088(param_1,piVar2,extraout_ECX);
  if (0 < piVar2[2]) {
    local_14 = FUN_0040f70c((int)piVar2,param_2);
    iVar4 = local_14;
    if (local_14 == -1) {
      if ((char)param_3 == '\0') {
        local_14 = 0;
        iVar4 = local_14;
      }
      else {
        local_14 = piVar2[2] + -1;
        iVar4 = local_14;
      }
    }
    do {
      if ((char)param_3 == '\0') {
        if (iVar4 == 0) {
          iVar4 = piVar2[2];
        }
        iVar4 = iVar4 + -1;
      }
      else {
        iVar4 = iVar4 + 1;
        if (iVar4 == piVar2[2]) {
          iVar4 = 0;
        }
      }
      piVar3 = (int *)FUN_0040f6b0(piVar2,iVar4);
      cVar1 = FUN_00403088(piVar3,extraout_EDX,extraout_ECX_00);
      if (((cVar1 != '\0') && ((param_5 == '\0' || ((char)piVar3[0x5d] != '\0')))) &&
         ((param_4 == '\0' || ((int *)piVar3[9] == param_1)))) {
        local_10 = piVar3;
      }
    } while ((local_10 == (int *)0x0) && (iVar4 != local_14));
  }
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_00445c39;
  puStack_2c = (undefined1 *)0x445c31;
  FUN_00402eac(piVar2);
  return;
}

