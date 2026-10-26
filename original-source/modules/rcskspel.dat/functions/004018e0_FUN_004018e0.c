/*
 * FUN_004018e0 at 004018e0
 * undefined FUN_004018e0(void)
 * Address ranges: 004018da-004019e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004018e0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar3 = 0;
  if (0 < DAT_00508610) {
    piVar4 = &DAT_00503ef0;
    do {
      if (*piVar4 == unaff_EDI) break;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0x47;
    } while (iVar3 < DAT_00508610);
  }
  if (iVar3 == DAT_00508610) {
    FUN_004afee0(s_Racer_not_found__File__s_Line__d_004dd980,
                 s_D__work_rcsk_Code_game_ai_cfun_c_004dd95c,0x16a);
  }
  else if ((&DAT_00503ef4)[iVar3 * 0x47] == 9) {
    return 0;
  }
  iVar3 = unaff_EDI * 0xd0 + DAT_0067ee20;
  if ((ABS(*(float *)(iVar3 + 0x9c)) + ABS(*(float *)(iVar3 + 0xa4)) < _DAT_00505030) &&
     (iVar5 = *(int *)(*(int *)((int)&DAT_00503ef0 + unaff_ESI) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9
              + DAT_006a5c38,
     iVar3 = *(int *)(*(int *)(&DAT_00503ef8 + unaff_ESI) * 0xd0 + 0xc + DAT_0067ee20),
     fVar1 = *(float *)(iVar5 + 0x50) - *(float *)(DAT_006a5c38 + iVar3 + 0x50 + iVar3 * 0xa8),
     fVar2 = *(float *)(iVar5 + 0x58) - *(float *)(DAT_006a5c38 + iVar3 + 0x58 + iVar3 * 0xa8),
     fVar1 * fVar1 + fVar2 * fVar2 < 5000.0)) {
    return 1;
  }
  return 0;
}

