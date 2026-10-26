/*
 * FUN_004715e0 at 004715e0
 * undefined FUN_004715e0(void)
 * Address ranges: 004715e0-004716fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004715e0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = param_3;
  if ((param_3 < 0) || (0xb < param_3)) {
    FUN_004afee0(s__s__d____Illegal_index__d_004f6958,s_D__work_rcsk_Code_game_rcr_stop__004f6928,
                 0x240,param_3);
  }
  if (*(int *)(param_1 + param_3 * 4) != 0) {
    uVar2 = FUN_00471700(param_2);
    if ((param_2 == 2) && (DAT_0053b9f0 != 0)) {
      iVar5 = *(int *)(param_1 + 0x90 + param_3 * 8);
      iVar3 = (*(int *)(param_1 + 0x30 + param_3 * 8) * 0x280) / DAT_004fe930;
      param_2 = (*(int *)(param_1 + 0x34 + param_3 * 8) * 0x1e0) / DAT_004fe934;
      iVar7 = (iVar5 * 0x280) / DAT_004fe930 + iVar3;
      iVar6 = *(int *)(param_1 + 0x94 + param_3 * 8);
      iVar4 = (iVar6 * 0x1e0) / DAT_004fe934 + param_2;
      param_3 = iVar3;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x30 + param_3 * 8);
      param_2 = *(int *)(param_1 + 0x34 + param_3 * 8);
      iVar5 = *(int *)(param_1 + 0x90 + param_3 * 8);
      iVar6 = *(int *)(param_1 + 0x94 + param_3 * 8);
      iVar7 = iVar5 + iVar3;
      iVar4 = param_2 + iVar6;
      param_3 = iVar3;
    }
    FUN_004b6ec0(*(undefined4 *)(param_1 + iVar1 * 4),uVar2,0,0,iVar5,iVar6,param_3,param_2,iVar7,
                 iVar4,param_4);
    return;
  }
  FUN_00470f50(param_2,param_3);
  return;
}

