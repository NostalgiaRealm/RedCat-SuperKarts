/*
 * FUN_0040e270 at 0040e270
 * undefined FUN_0040e270(void)
 * Address ranges: 0040e270-0040e45e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040e270(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  iVar6 = param_1 * 0x11c;
  iVar7 = *(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20) + 1;
  if (iVar7 == DAT_00680b2c) {
    iVar7 = 0;
  }
  iVar2 = FUN_00411250((&DAT_00503ef0)[param_1 * 0x47],1,0xffffffff,5,3);
  if (iVar2 < 0) {
    FUN_004afee0(s__s__d____Could_not_initialize_th_004df158,
                 s_D__work_rcsk_Code_game_ai_rcr_ha_004df128,0xa3,
                 *(undefined4 *)(&DAT_00503f10 + iVar6),iVar2);
  }
  iVar3 = FUN_00411320(iVar2);
  iVar8 = iVar3 * 0x50 + DAT_00680ae0;
  iVar5 = *(int *)(iVar3 * 0x50 + 0x14 + DAT_00680ae0);
  if (((iVar5 == -1) && (iVar5 = *(int *)(iVar8 + 0x1c), iVar5 == -1)) &&
     (iVar5 = *(int *)(iVar8 + 0x18), iVar5 == -1)) {
    iVar5 = iVar3;
  }
  iVar3 = iVar5 * 0x50 + DAT_00680ae0;
  iVar8 = *(int *)(iVar3 + 0x14);
  iVar5 = *(int *)(iVar3 + 0x1c);
  iVar3 = *(int *)(iVar3 + 0x18);
  if ((iVar8 == -1) || (*(int *)(iVar8 * 0x50 + 4 + DAT_00680ae0) != 0x42)) {
    if ((iVar5 == -1) || (*(int *)(iVar5 * 0x50 + 4 + DAT_00680ae0) != 0x42)) {
      if ((iVar3 == -1) || (*(int *)(iVar3 * 0x50 + 4 + DAT_00680ae0) != 0x42)) {
        iVar5 = *(int *)(DAT_00680b28 + 0xe8 + iVar7 * 0x984);
        iVar3 = 0;
        if (0 < iVar5) {
          piVar4 = (int *)(DAT_00680b28 + iVar7 * 0x984 + 0x154);
          do {
            iVar7 = *piVar4;
            if (*(int *)(iVar7 * 0x50 + 4 + DAT_00680ae0) == 0x42) {
              FUN_004113c0(iVar7,auStack_18);
              iVar8 = iVar7;
              break;
            }
            iVar3 = iVar3 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar3 < iVar5);
        }
      }
      else {
        FUN_004113c0(iVar3,auStack_18);
        iVar8 = iVar3;
      }
    }
    else {
      FUN_004113c0(iVar5,auStack_18);
      iVar8 = iVar5;
    }
  }
  else {
    FUN_004113c0(iVar8,auStack_18);
  }
  iVar7 = FUN_0040e0c0(param_1,iVar8);
  FUN_004113c0(iVar7,auStack_c);
  *(undefined4 *)(&DAT_00503f34 + iVar6) = 0;
  uVar1 = *(undefined4 *)(&DAT_00503f10 + iVar6);
  *(int *)(&DAT_00503f10 + iVar6) = iVar7;
  if (iVar7 < 0) {
    *(undefined4 *)(&DAT_00503f10 + iVar6) = uVar1;
  }
  else {
    FUN_004010e0(param_1,auStack_c);
  }
  FUN_00401200(param_1,auStack_18);
  FUN_004112d0(iVar2);
  return;
}

