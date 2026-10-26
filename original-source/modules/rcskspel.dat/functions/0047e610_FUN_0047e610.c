/*
 * FUN_0047e610 at 0047e610
 * undefined FUN_0047e610(void)
 * Address ranges: 0047e610-0047e73d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0047e6fe) */

int __fastcall FUN_0047e610(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_4;
  
  if (*(int *)(param_1 + 0x74) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*(int *)(param_1 + 0x78) - *(int *)(param_1 + 0x74)) / 0x14;
  }
  uStack_4 = param_1;
  FUN_004afce0(s__s__d____Clearing_Items__d__004f8a70,s_D__work_rcsk_Code_game_Requester_004f8a48,
               0xb8,iVar2);
  iVar4 = 0;
  iVar2 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x74) == 0) {
      iVar3 = 0;
      iVar1 = 0;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x78) - *(int *)(param_1 + 0x74);
      iVar1 = iVar3 * 0x66666667;
      iVar3 = iVar3 / 0x14;
    }
    if (iVar3 <= iVar4) {
      iVar4 = *(int *)(param_1 + 0x78);
      iVar2 = *(int *)(param_1 + 0x74);
      for (iVar3 = iVar2; iVar3 != iVar4; iVar3 = iVar3 + 0x14) {
        iVar1 = FUN_0040b4b0();
      }
      *(int *)(param_1 + 0x78) = iVar2;
      return iVar1;
    }
    FUN_004afce0(s__s__d____Deleting_item__d_004f8ab8,s_D__work_rcsk_Code_game_Requester_004f8a90,
                 0xc0,iVar4);
    if (iVar2 < 0) break;
    iVar1 = *(int *)(param_1 + 0x74);
    if (iVar1 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(param_1 + 0x78) - iVar1) / 0x14;
    }
    if (iVar3 <= iVar4) break;
    iVar1 = *(int *)(iVar1 + 0x10 + iVar2);
    if (iVar1 != 0) {
      FUN_00480010();
      FUN_004bc150(iVar1);
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 0x14;
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int)&uStack_4 + 3,&DAT_004da5d0);
}

