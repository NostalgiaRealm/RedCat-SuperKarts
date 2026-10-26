/*
 * FUN_00443f10 at 00443f10
 * undefined FUN_00443f10(void)
 * Address ranges: 00443f10-00443fec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00443f10(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_c [8];
  undefined4 local_4;
  
  iVar5 = *(int *)(param_1 + 4);
  puVar3 = (undefined4 *)
           FUN_00445120(local_c,*(undefined4 *)(param_1 + 0x18),iVar5,*(int *)(param_1 + 8) % iVar5,
                        *(undefined4 *)(param_1 + 0xc),
                        CONCAT31((int3)((uint)(*(int *)(param_1 + 8) / iVar5) >> 8),
                                 *(undefined1 *)(param_1 + 0x1d)));
  uVar1 = *puVar3;
  uVar2 = puVar3[1];
  local_4 = puVar3[2];
  if (DAT_0053f4f4 == 0) {
    DAT_0053f4f4 = GetTickCount();
    return DAT_0053f4f4 & 0xffffff00;
  }
  DVar4 = GetTickCount();
  iVar5 = (int)(DVar4 - DAT_0053f4f4) / 0x19;
  if (iVar5 != 0) {
    DAT_0053f4f4 = GetTickCount();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar5;
  }
  iVar5 = *(int *)(param_1 + 4) + -2;
  if (iVar5 <= *(int *)(param_1 + 8)) {
    return CONCAT31((int3)((uint)iVar5 >> 8),1);
  }
  uVar6 = FUN_004988a0(uVar1,uVar2,local_4);
  return uVar6 & 0xffffff00;
}

