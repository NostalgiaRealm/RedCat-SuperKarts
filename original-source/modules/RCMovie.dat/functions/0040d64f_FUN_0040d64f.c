/*
 * FUN_0040d64f at 0040d64f
 * undefined __cdecl FUN_0040d64f(int param_1, int param_2)
 * Address ranges: 0040d64f-0040d82c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0040d64f(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  HWND hWnd;
  int iVar3;
  uint local_18;
  int local_c;
  
  local_c = 0;
  bVar1 = false;
  FUN_00404b2d();
  iVar2 = FUN_00412061();
  if (iVar2 == 1) {
    param_2 = 2;
  }
  hWnd = GetFocus();
  SetFocus(DAT_0043842c);
  FUN_0040f8b1(0,param_2,0,0,DAT_0042c350,DAT_0042c354,0);
  iVar2 = FUN_0041289c();
  if (iVar2 == 0) {
    FUN_0040187a((byte *)s__s__d_____play_help__empty_form_o_004323f4);
  }
  do {
    if ((*(int *)(param_1 + local_c * 8) == -1) || (bVar1)) {
      FUN_004066a0(local_18);
      iVar2 = FUN_00412061();
      if (iVar2 == 0) {
        FUN_0040f8b1(param_2,0,0,0,DAT_0042c350,DAT_0042c354,0);
      }
      else if (iVar2 == 1) {
        FUN_0040f8b1(param_2,1,0,0,DAT_0042c350,DAT_0042c354,0);
        FUN_00401cf3();
      }
      SetFocus(hWnd);
      FUN_00404aee();
      return;
    }
    iVar3 = FUN_00412061();
    FUN_0040d38d(iVar3);
    if ((*(int *)(param_1 + local_c * 8) < 0) || (iVar2 < *(int *)(param_1 + local_c * 8))) {
      FUN_0040187a((byte *)s__s__d_____play_help__illegal_for_00432438);
    }
    local_18 = FUN_00407f2c(*(uint **)(param_1 + 4 + local_c * 8),0);
    FUN_00412bb8(*(int *)(param_1 + local_c * 8));
    iVar3 = FUN_00412061();
    if (iVar3 == 1) {
      FUN_00401cf3();
    }
    do {
      iVar3 = FUN_00406327(local_18);
      if (iVar3 == 0) goto LAB_0040d7a1;
      iVar3 = FUN_0040d82d();
    } while (iVar3 == 0);
    bVar1 = true;
LAB_0040d7a1:
    local_c = local_c + 1;
  } while( true );
}

