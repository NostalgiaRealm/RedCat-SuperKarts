/*
 * FUN_0044c520 at 0044c520
 * undefined FUN_0044c520(void)
 * Address ranges: 0044c520-0044c661
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044c520(undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cd942;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != (undefined4 *)0x0) {
    ExceptionList = &local_c;
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    param_1[6] = param_2[6];
    *(undefined1 *)(param_1 + 7) = *(undefined1 *)(param_2 + 7);
    *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    FUN_00412870(param_2 + 8,0,0xffffffff);
    local_4._0_1_ = 1;
    *(undefined1 *)(param_1 + 0xc) = *(undefined1 *)(param_2 + 0xc);
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    FUN_00412870(param_2 + 0xc,0,0xffffffff);
    local_4._0_1_ = 2;
    *(undefined1 *)(param_1 + 0x10) = *(undefined1 *)(param_2 + 0x10);
    FUN_0040b4f0(0);
    FUN_00412870(param_2 + 0x10,0,0xffffffff);
    local_4 = CONCAT31(local_4._1_3_,3);
    *(undefined1 *)(param_1 + 0x14) = *(undefined1 *)(param_2 + 0x14);
    if (param_2[0x15] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (int)(param_2[0x16] - param_2[0x15]) >> 2;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    pvVar1 = operator_new(iVar2 << 2);
    param_1[0x15] = pvVar1;
    iVar2 = param_2[0x16];
    for (iVar3 = param_2[0x15]; iVar3 != iVar2; iVar3 = iVar3 + 4) {
      FUN_0043a120(pvVar1,iVar3);
      pvVar1 = (void *)((int)pvVar1 + 4);
    }
    param_1[0x16] = pvVar1;
    param_1[0x17] = pvVar1;
  }
  ExceptionList = local_c;
  return;
}

