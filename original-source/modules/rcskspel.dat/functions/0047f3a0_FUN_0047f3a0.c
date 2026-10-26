/*
 * FUN_0047f3a0 at 0047f3a0
 * undefined FUN_0047f3a0(void)
 * Address ranges: 0047f3a0-0047f4a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047f3a0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_4;
  
  uStack_4 = param_1;
  FUN_004afce0(s__s__d____HandleEachItem_enters_004f9200,s_D__work_rcsk_Code_game_Requester_004f91d8
               ,0x212);
  *param_1 = 0;
  if (param_1[0x1d] == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)(param_1[0x1e] - param_1[0x1d]) / 0x14;
  }
  FUN_004afce0(s__s__d____Items__d_004f9248,s_D__work_rcsk_Code_game_Requester_004f9220,0x217,iVar1)
  ;
  iVar1 = 0;
  iVar4 = 0;
  while( true ) {
    if (param_1[0x1d] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (int)(param_1[0x1e] - param_1[0x1d]) / 0x14;
    }
    if (iVar2 <= iVar1) {
      FUN_004afce0(s__s__d____HandleEachItem_leaves_004f92c8,
                   s_D__work_rcsk_Code_game_Requester_004f92a0,0x21e);
      return;
    }
    FUN_004afce0(s__s__d____Handling_item__d_004f9284,s_D__work_rcsk_Code_game_Requester_004f925c,
                 0x21a,iVar1);
    if (iVar4 < 0) break;
    iVar2 = param_1[0x1d];
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (param_1[0x1e] - iVar2) / 0x14;
    }
    if (iVar3 <= iVar1) break;
    (**(code **)(**(int **)(iVar2 + 0x10 + iVar4) + 0x18))();
    iVar1 = iVar1 + 1;
    iVar4 = iVar4 + 0x14;
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int)&uStack_4 + 3,&DAT_004da5d0);
}

