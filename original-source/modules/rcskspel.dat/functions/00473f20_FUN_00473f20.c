/*
 * FUN_00473f20 at 00473f20
 * undefined FUN_00473f20(void)
 * Address ranges: 00473f20-00473fa5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473f20(undefined1 *param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined4 local_4;
  
  bVar1 = false;
  local_4 = 0xffffffff;
  do {
    iVar3 = FUN_00474040();
    if (iVar3 < 3) {
      if ((iVar3 == 2) || (iVar3 == 0)) {
        FUN_00473fb0(5,s_click4_wav_004f77d0);
        bVar1 = true;
        *param_1 = 1;
      }
      else if (iVar3 == 1) goto LAB_00473f6f;
    }
    else {
      if (iVar3 == 3) {
LAB_00473f6f:
        pcVar4 = s_click4_wav_004f77dc;
      }
      else {
        if (iVar3 != 10000) goto LAB_00473f83;
        pcVar4 = s_click4_wav_004f77c4;
      }
      FUN_00473fb0(8,pcVar4);
      bVar1 = true;
      *param_1 = 0;
    }
LAB_00473f83:
    cVar2 = FUN_00471b80();
    if (cVar2 != '\0') {
      FUN_004739c0(&local_4);
      FUN_004aff70();
    }
    if (bVar1) {
      return;
    }
  } while( true );
}

