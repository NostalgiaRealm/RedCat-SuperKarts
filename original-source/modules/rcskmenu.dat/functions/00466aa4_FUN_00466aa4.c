/*
 * FUN_00466aa4 at 00466aa4
 * undefined __register FUN_00466aa4(int * param_1, int param_2)
 * Address ranges: 00466aa4-00466b71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466aa4(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  WPARAM WVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  int local_10;
  int local_c;
  int local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_10 = 0;
  puStack_24 = &LAB_00466b72;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  local_8 = param_2;
  iVar2 = (**(code **)(*(int *)param_1[0x84] + 0x14))();
  if (-1 < iVar2 + -1) {
    WVar3 = 0;
    local_c = iVar2;
    do {
      (**(code **)(*(int *)param_1[0x84] + 0xc))((int *)param_1[0x84],WVar3,&local_10);
      cVar1 = FUN_0042984c(CONCAT22((short)((uint)local_8 >> 0x10),*(undefined2 *)(local_8 + 4)),
                           local_10);
      if (cVar1 != '\0') {
        cVar1 = (**(code **)(*param_1 + 0xb4))(param_1,WVar3);
        if (cVar1 != '\0') {
          cVar1 = FUN_00403088(param_1,extraout_EDX,extraout_ECX);
          if (cVar1 != '\0') {
            *(undefined4 *)(local_8 + 0xc) = 1;
            cVar1 = FUN_00403088(param_1,extraout_EDX_00,extraout_ECX_00);
            if (cVar1 != '\0') {
              FUN_0046655c(param_1,WVar3);
              FUN_00403088(param_1,extraout_EDX_01,extraout_ECX_01);
            }
            goto LAB_00466b5c;
          }
        }
      }
      WVar3 = WVar3 + 1;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  FUN_00444c4c((int)param_1,local_8);
LAB_00466b5c:
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00466b79;
  puStack_24 = (undefined1 *)0x466b71;
  FUN_00403b50(&local_10);
  return;
}

