/*
 * FUN_00401400 at 00401400
 * undefined4 __stdcall FUN_00401400(HINSTANCE param_1, undefined4 param_2, LPCSTR param_3, int param_4)
 * Address ranges: 00401400-0040158d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401400(HINSTANCE param_1,undefined4 param_2,LPCSTR param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int local_18;
  int local_14;
  CRect aCStack_10 [16];
  
  FUN_00401250();
  if (DAT_004383a8 == -1) {
    FUN_004015a6((byte *)s__s__d__No_playback_requested___S_0042c28c);
    return 0;
  }
  iVar1 = FUN_00401000(param_3);
  if (iVar1 != 0) {
    FUN_00401160();
    FUN_00401e18(1,0x40,1);
    FUN_00401e18(2,0,0);
    if (iVar1 == 1) {
      uVar2 = FUN_004012a0(&local_14,&local_18);
      if ((char)uVar2 == '\0') {
        return 0;
      }
    }
    else if ((iVar1 == 2) && (uVar2 = FUN_00401350(&local_14,&local_18), (char)uVar2 == '\0')) {
      return 0;
    }
    FUN_00403f60(param_1,param_4,s_Davilex_Entertainment_0042c264,s_Movie_player_0042c27c);
    FUN_004010f0();
    if (iVar1 == 1) {
      FUN_0040a0e0(0);
      FUN_004015a6((byte *)s__s__d__Playing_Smacker____0042c218);
      FUN_0040a616(param_3,0,0,local_14,local_18,1,0);
    }
    else if (iVar1 == 2) {
      FUN_0041e730();
      FUN_004015a6((byte *)s__s__d__Playing_AVI____0042c234);
      puVar3 = (undefined4 *)CRect::CRect(aCStack_10,0,0,local_14,local_18);
      FUN_0041e870(&stack0xffffffcc,puVar3);
      FUN_0041e4e0(0,param_3);
      FUN_0041e760();
    }
    else {
      FUN_0040187a((byte *)s_Unknown_movie_format__0042c24c);
    }
    FUN_0040a088();
    FUN_00406d14();
    FUN_0040173e();
    return 0;
  }
  return 1;
}

