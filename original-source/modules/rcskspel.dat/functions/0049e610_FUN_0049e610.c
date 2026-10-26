/*
 * FUN_0049e610 at 0049e610
 * undefined FUN_0049e610(void)
 * Address ranges: 0049e610-0049e939
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049e610(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 local_170 [4];
  char *local_16c;
  undefined1 local_160 [4];
  char *local_15c;
  CHAR local_150 [12];
  undefined1 local_144 [4];
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d16d1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0049f040();
  iVar7 = 0;
  local_4 = 0;
  iVar2 = FUN_004b1ed0(s_SndTypes_004fc448,s_count_004fba1c);
  FUN_0049f250(iVar2,0,499,s_D__work_rcracer_oursoundlib_soun_004fc23c,0x168);
  if (0 < iVar2) {
    do {
      wsprintfA(local_150,&DAT_004fb9fc,iVar7);
      FUN_004b1f10(s_SndTypes_004fc448,local_150,local_10c,0xff);
      iVar4 = -1;
      pcVar8 = local_10c;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_0049f2a0(iVar4 != -2,s__s__d__Can_t_find_sound_type__d_s_004fc41c,
                   s_D__work_rcracer_oursoundlib_soun_004fc23c,0x16f,iVar7);
      iVar4 = FUN_004b1f60(local_10c,0);
      FUN_0049f2a0(iVar4 == 7,s__s___d__Incorrect_number_of_argu_004fc3bc,
                   s_D__work_rcracer_oursoundlib_soun_004fc23c,0x175,iVar7,iVar4,7);
      FUN_004b2110(0,local_10c,0xff);
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar8 = local_10c;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5 - 1;
      cVar1 = FUN_0040b600(uVar5,1);
      if (cVar1 != '\0') {
        pcVar8 = local_10c;
        pcVar9 = local_15c;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar9 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar9 = pcVar9 + 1;
        }
        FUN_0040b5e0(uVar5);
      }
      local_4._0_1_ = 1;
      FUN_00412870(local_160,0,0xffffffff);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0040b4f0(1);
      FUN_004b2110(1,local_10c,0xff);
      FUN_0040b4f0(0);
      uVar5 = 0xffffffff;
      pcVar8 = local_10c;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5 - 1;
      cVar1 = FUN_0040b600(uVar5,1);
      if (cVar1 != '\0') {
        pcVar8 = local_10c;
        pcVar9 = local_16c;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar9 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar9 = pcVar9 + 1;
        }
        FUN_0040b5e0(uVar5);
      }
      local_4._0_1_ = 2;
      FUN_00412870(local_170,0,0xffffffff);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0040b4f0(1);
      local_140 = FUN_004b20c0(2);
      uVar3 = FUN_004b20c0(3);
      FUN_0049f250(uVar3,0,100,s___csndtype_h_004fbd80,0xfe);
      local_134 = uVar3;
      uVar3 = FUN_004b20c0(4);
      FUN_0049f250(uVar3,0,4000,s___csndtype_h_004fbd80,0xd9);
      local_138 = uVar3;
      uVar3 = FUN_004b20c0(5);
      FUN_0049f250(uVar3,0,100,s___csndtype_h_004fbd80,0x112);
      local_130 = uVar3;
      FUN_004b2110(6,local_10c,0xff);
      local_13c = FUN_0049e370(local_10c);
      FUN_0049ed10(local_144);
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar2);
  }
  local_4 = 0xffffffff;
  FUN_0049f1a0();
  ExceptionList = local_c;
  return;
}

