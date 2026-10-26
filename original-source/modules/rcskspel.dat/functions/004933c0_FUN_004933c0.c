/*
 * FUN_004933c0 at 004933c0
 * undefined FUN_004933c0(void)
 * Address ranges: 004933c0-00493426
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004933c0(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((param_2 < 0) || (DAT_00680b2c < param_2)) {
    FUN_004afee0(s___s___d_Illegal_chunk___d_004fab60,s_D__work_rcsk_Code_Engine_Prog_If_004faa80,
                 0x139,param_2);
  }
  iVar4 = FUN_00493430(param_2,param_3,param_4);
  puVar1 = (undefined4 *)(iVar4 * 0x50 + 8 + DAT_00680ae0);
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  *param_1 = *puVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  return;
}

