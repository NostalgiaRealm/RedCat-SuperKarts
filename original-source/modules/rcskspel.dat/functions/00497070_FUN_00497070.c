/*
 * FUN_00497070 at 00497070
 * undefined FUN_00497070(void)
 * Address ranges: 00497070-004971ee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00497070(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [32];
  
  iVar1 = param_2;
  iVar2 = FUN_004b96d0(param_2);
  if (iVar2 == 0) {
    FUN_004afee0(s__s__d____File_open_failed_for_fi_004face0,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fb234,0x1b7,iVar1);
  }
  FUN_004bf930(&param_2,4,1,iVar2);
  iVar3 = 0;
  if (0 < param_2) {
    do {
      FUN_004bf930(&uStack_44,4,1,iVar2);
      FUN_004bf930(&uStack_3c,4,1,iVar2);
      FUN_004bf930(&uStack_38,4,1,iVar2);
      FUN_004bf930(&uStack_34,4,1,iVar2);
      FUN_004bf930(&uStack_30,4,1,iVar2);
      FUN_004bf930(&uStack_2c,4,1,iVar2);
      FUN_004bf930(&uStack_28,4,1,iVar2);
      FUN_004bf930(&uStack_24,4,1,iVar2);
      FUN_004bf930(auStack_20,1,0x20,iVar2);
      FUN_004bf930(&uStack_40,4,1,iVar2);
      FUN_0043e140(uStack_3c,auStack_20,iVar1,uStack_2c,uStack_28,uStack_24,uStack_38,uStack_34,
                   uStack_30,uStack_40,uStack_44,*(undefined4 *)(param_1 + 0x9a));
      FUN_004afce0(s_Currently_loaded_objects___d_of___004fb260,iVar3,param_2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  FUN_004b9840(iVar2);
  return;
}

