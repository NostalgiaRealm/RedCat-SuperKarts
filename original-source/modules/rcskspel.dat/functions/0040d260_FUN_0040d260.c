/*
 * FUN_0040d260 at 0040d260
 * undefined FUN_0040d260(void)
 * Address ranges: 0040d260-0040d30d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d260(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cccd8;
  local_c = ExceptionList;
  if (param_2 == -1) {
    ExceptionList = &local_c;
    FUN_004afce0(s__s__d____Playing_voice_004def40,s_D__work_rcsk_Code_game_ai_rcr_ch_004def10,0x68)
    ;
    uVar2 = FUN_00438090(local_1c);
    local_4 = 0;
    FUN_004387a0(param_1,uVar2);
    local_4 = 0xffffffff;
    if (local_18 != 0) {
      cVar1 = *(char *)(local_18 + -1);
      if ((cVar1 == '\0') || (cVar1 == -1)) {
        FUN_004bc150((char *)(local_18 + -1));
      }
      else {
        *(char *)(local_18 + -1) = cVar1 + -1;
      }
    }
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    FUN_004afce0(s__s__d____Done_playing_voice_004def88,s_D__work_rcsk_Code_game_ai_rcr_ch_004def58,
                 0x6a);
  }
  ExceptionList = local_c;
  return;
}

