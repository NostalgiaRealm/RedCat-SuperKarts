/*
 * FUN_00443d0c at 00443d0c
 * undefined __register FUN_00443d0c(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00443d0c-00443dea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443d0c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int *piVar3;
  HKL hkl;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined *local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = (undefined *)0x0;
  puStack_1c = &LAB_00443deb;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  if (PTR_DAT_0047c9d8[8] != '\0') {
    puVar1 = &stack0xfffffffc;
    if (param_1[0x56] != 0) {
      FUN_004305c0(*(int *)PTR_DAT_0047c9bc,(int *)&local_8,param_3);
      iVar2 = FUN_00407db0((undefined *)param_1[0x56],local_8);
      puVar1 = puStack_18;
      if (iVar2 != 0) {
        piVar3 = (int *)FUN_004303c0(*(int *)PTR_DAT_0047c9bc,extraout_EDX,extraout_ECX);
        iVar2 = (**(code **)(*piVar3 + 0x14))();
        puVar1 = puStack_18;
        if (iVar2 != 0) {
          hkl = *(HKL *)(*(int *)PTR_DAT_0047c9bc + 0x30);
          if ((char)param_1[0x55] != '\0') {
            piVar3 = (int *)FUN_004303c0(*(int *)PTR_DAT_0047c9bc,extraout_EDX_00,extraout_ECX_00);
            iVar2 = (**(code **)(*piVar3 + 0x50))(piVar3,param_1[0x56]);
            if (-1 < iVar2) {
              piVar3 = (int *)FUN_004303c0(*(int *)PTR_DAT_0047c9bc,extraout_EDX_01,extraout_ECX_01)
              ;
              hkl = (HKL)(**(code **)(*piVar3 + 0x18))(piVar3,iVar2);
            }
          }
          ActivateKeyboardLayout(hkl,1);
          puVar1 = puStack_18;
        }
      }
    }
    puStack_18 = puVar1;
    iVar2 = FUN_00445724(param_1);
    FUN_00449bd0(iVar2,(char)param_1[0x55]);
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00443df2;
  puStack_1c = (undefined1 *)0x443dea;
  FUN_00403b50((int *)&local_8);
  return;
}

