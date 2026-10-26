/*
 * FUN_00492620 at 00492620
 * undefined FUN_00492620(void)
 * Address ranges: 00492620-0049272d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00492620(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 * 0xd0;
  iVar2 = *(int *)(iVar4 + 0x8c + DAT_0067ee20);
  if (9 < iVar2) {
    FUN_004afee0(s__s__d____No_more_sub_objects_ava_004fa93c,
                 s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x69c);
  }
  iVar3 = FUN_004a02b0(param_4,param_5,param_6,param_7,param_8,param_9,param_2,param_3,FUN_004a0610)
  ;
  iVar1 = iVar4 + DAT_0067ee20;
  if ((iVar2 < 0) || (9 < iVar2)) {
    FUN_004afee0(s__s__d____illegal_sub_object_inde_004fa5bc,
                 s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x25f,iVar2);
  }
  *(int *)(iVar1 + 100 + iVar2 * 4) = iVar3;
  *(undefined4 *)(iVar3 * 0xa9 + 0xa1 + DAT_006a5c38) = 2;
  *(int *)(iVar3 * 0xa9 + 0xc + DAT_006a5c38) = param_1;
  *(int *)(iVar4 + 0x8c + DAT_0067ee20) = *(int *)(iVar4 + 0x8c + DAT_0067ee20) + 1;
  FUN_004a09e0();
  return;
}

