/*
 * FUN_004903c0 at 004903c0
 * undefined FUN_004903c0(void)
 * Address ranges: 004903c0-004906a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004903c0(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 uStack_10;
  float local_c;
  undefined4 uStack_8;
  undefined1 local_4 [4];
  
  iVar5 = DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9;
  FUN_00495fe0(*(undefined4 *)(iVar5 + 0x50),*(undefined4 *)(iVar5 + 0x54),
               *(undefined4 *)(iVar5 + 0x58),&local_1c,&local_18,local_4);
  uVar1 = FUN_00496360(local_18,local_1c);
  iVar6 = 0;
  uStack_8 = 0;
  local_c = (float)(*(uint *)(param_1 + 0x34) >> 0x18);
  local_14 = ABS(*(float *)(param_1 + 0xa4)) * 0.1 + 1.0;
  FUN_0048f4e0();
  local_14 = (float)(uVar1 & 0xff);
  uStack_10 = 0;
  iVar2 = __ftol();
  uVar1 = __ftol();
  uVar3 = __ftol();
  uVar4 = __ftol();
  *(uint *)(param_1 + 0x34) = ((uVar1 | iVar2 << 8) << 8 | uVar3) << 8 | uVar4;
  uVar1 = __ftol();
  uVar3 = __ftol();
  uVar4 = __ftol();
  iVar5 = *(int *)(param_1 + 0xc);
  uVar4 = ((uVar1 | iVar2 << 8) << 8 | uVar3) << 8 | uVar4;
  iVar2 = *(int *)(DAT_006a5c38 + iVar5 + iVar5 * 0xa8);
  iVar5 = DAT_006a5c38 + iVar5 + iVar5 * 0xa8;
  if (iVar2 == 1) {
    iVar5 = *(int *)(iVar5 + 0x99);
  }
  else if (iVar2 == 2) {
    iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) * 9 + 4 + DAT_006a5f78) +
                             *(int *)(iVar5 + 8) * 4) * 0x10 + DAT_006a5f30);
  }
  else {
    FUN_004afee0(s___s___d_Invalid_object_type__004fa56c);
    iVar5 = 0;
  }
  iVar2 = 0;
  iVar5 = iVar5 * 0xbc;
  if (0 < *(int *)(iVar5 + 0x84 + DAT_006a5ee0)) {
    do {
      iVar2 = iVar2 + 1;
      *(uint *)(*(int *)(iVar5 + 0x80 + DAT_006a5ee0) + 0x10 + iVar6) = uVar4;
      iVar6 = iVar6 + 0x20;
    } while (iVar2 < *(int *)(iVar5 + 0x84 + DAT_006a5ee0));
  }
  FUN_004902d0(uVar4);
  return;
}

