/*
 * FUN_0041d540 at 0041d540
 * undefined FUN_0041d540(void)
 * Address ranges: 0041d540-0041d6b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041d540(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((param_1 < 0) || (10 < param_1)) {
    FUN_004afee0(s__init_topview_camera__illegal_ca_004e2f94,param_1,10);
  }
  uVar4 = FUN_00498280();
  iVar3 = DAT_006a5c38;
  iVar1 = DAT_0053be28;
  (&DAT_00508620)[param_1] = uVar4;
  iVar2 = *(int *)(iVar1 * 0xd0 + 0xc + DAT_0067ee20);
  iVar1 = iVar3 + iVar2 + 0x50 + iVar2 * 0xa8;
  FUN_004988a0(*(undefined4 *)(iVar3 + iVar2 + 0x50 + iVar2 * 0xa8),*(float *)(iVar1 + 4) + 15.0,
               *(undefined4 *)(iVar1 + 8));
  FUN_00498a50(*(undefined4 *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20),0x42c80000,0x41700000,0);
  FUN_00498b50(*(undefined4 *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20),0,0x41700000,0);
  return;
}

