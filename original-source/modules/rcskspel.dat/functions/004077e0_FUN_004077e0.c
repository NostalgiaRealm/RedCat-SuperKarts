/*
 * FUN_004077e0 at 004077e0
 * undefined FUN_004077e0(void)
 * Address ranges: 004077e0-00407936
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004077e0(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined1 auStack_148 [8];
  undefined1 auStack_140 [32];
  undefined1 auStack_120 [32];
  undefined1 auStack_100 [256];
  
  FUN_004b1d60(0x4de940);
  FUN_004b1f10(s_AI_BEHAVIOR_004de954,s_TBDFile_004de94c,auStack_140,0x1f);
  FUN_004b1d60(auStack_140);
  DAT_00505060 = FUN_004b1ed0(s_TRAFFIC_TYPES_004de968,s_RANDOM_004de960);
  DAT_00505064 = FUN_004b1ed0(s_TRAFFIC_TYPES_004de980,s_COUNT_004de978);
  _DAT_004e0198 = FUN_004b1ed0(s_TRAFFIC_TYPES_004de9a4,s_MAX_TRAFFIC_RIGHT_004de990);
  _DAT_004e019c = FUN_004b1ed0(s_TRAFFIC_TYPES_004de9c8,s_MAX_TRAFFIC_LEFT_004de9b4);
  iVar4 = 0;
  if (0 < DAT_00505064) {
    piVar6 = (int *)&DAT_00505068;
    do {
      FUN_004bea92(auStack_148,0x4de9d8,iVar4);
      FUN_004b1f10(s_TRAFFIC_TYPES_004de9dc,auStack_148,auStack_100,0xff);
      iVar2 = FUN_004b1f60(auStack_100,0);
      if (iVar2 < 2) {
        FUN_004afee0(s___s___d_Not_enough_parameters_us_004dea10,
                     s_D__work_rcsk_Code_game_ai_nwtrf__004de9ec,0xcc);
      }
      iVar5 = 0;
      *piVar6 = 1;
      if (0 < iVar2 + -2) {
        do {
          FUN_004b2110(iVar5,auStack_120,0x1f);
          iVar3 = FUN_004076b0(auStack_120);
          iVar5 = iVar5 + 1;
          *piVar6 = *piVar6 + iVar3;
        } while (iVar5 < iVar2 + -2);
      }
      uVar1 = FUN_004b20c0(iVar5);
      *(undefined1 *)(piVar6 + 1) = uVar1;
      uVar1 = FUN_004b20c0(iVar5 + 1);
      *(undefined1 *)((int)piVar6 + 5) = uVar1;
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 2;
    } while (iVar4 < DAT_00505064);
  }
  return;
}

