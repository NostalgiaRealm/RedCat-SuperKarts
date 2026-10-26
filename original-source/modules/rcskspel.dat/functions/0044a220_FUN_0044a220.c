/*
 * FUN_0044a220 at 0044a220
 * undefined FUN_0044a220(void)
 * Address ranges: 0044a220-0044a5bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0044a27b) */

void __fastcall FUN_0044a220(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined4 *local_1c4;
  undefined1 local_1b8 [4];
  int local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  char local_1a4 [20];
  undefined1 local_190 [12];
  undefined1 local_184 [40];
  int local_15c;
  int local_158;
  undefined4 local_154;
  int local_124;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd877;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004b1d60(s_Race_ini_004f0624);
  uVar2 = FUN_004b1ed0(s_CHARDATA_004f0638,s_COUNT_004f0630);
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  FUN_004afce0(s_NO_of_characters__d_004f0644,uVar2);
  iVar7 = *(int *)(param_1 + 8);
  iVar5 = *(int *)(param_1 + 4);
  for (iVar6 = iVar5; iVar6 != iVar7; iVar6 = iVar6 + 0x78) {
    FUN_0044b430(0);
  }
  iVar7 = 0;
  *(int *)(param_1 + 8) = iVar5;
  if (0 < *(int *)(param_1 + 0x10)) {
    local_1c4 = &DAT_0050820c;
    do {
      FUN_004b1d60(s_Race_ini_004f065c);
      FUN_004be8cb(local_190,10,&DAT_004f0668,iVar7);
      FUN_004afce0(s_Reading_char___d_004f066c,iVar7);
      FUN_004b1f10(s_CHARDATA_004f0680,local_190,local_10c,0xff);
      iVar6 = FUN_004b1f60(local_10c,&DAT_004f068c);
      FUN_0044ce60();
      local_4 = 0;
      FUN_004b2110(1,local_1a4,0x14);
      FUN_004afce0(s_mesh__s_004f0690,local_1a4);
      uVar2 = FUN_004b20c0(2);
      local_1a8 = uVar2;
      FUN_004afce0(s__d__Person__d_of_INTEL_INI_004f069c,iVar7,uVar2);
      iVar5 = DAT_00508610;
      if ((DAT_00508610 <= iVar7) || (puVar3 = local_1c4 + -1, (int)local_1c4 < 0x50820c)) {
        puVar3 = &DAT_0053beb8;
      }
      *puVar3 = uVar2;
      if ((iVar5 <= iVar7) || (puVar3 = local_1c4, (int)local_1c4 < 0x50820c)) {
        puVar3 = &DAT_0053bebc;
      }
      uVar2 = FUN_00417eb0(local_1a4);
      *puVar3 = uVar2;
      FUN_004b1d60(s_CharAnim_Ini_004f06b8);
      DAT_00508614 = FUN_004b1ed0(s_TWEAK_004f06d4,s_turn_speed_004f06c8);
      iVar5 = 0;
      if (iVar6 < 4) {
        FUN_004afce0(s_____no_car_color_in_ini_file__d_004f06fc,0);
      }
      else {
        iVar5 = FUN_004b20c0(3);
        FUN_004afce0(s_____car_color_in_ini_file__d_004f06dc,iVar5);
      }
      FUN_00475360();
      iVar6 = FUN_00476560();
      if (iVar6 <= iVar5) {
        FUN_00475360();
        iVar5 = FUN_00476560();
        iVar5 = iVar5 + -1;
      }
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      FUN_004afce0(s_____resulting_car_color__d_004f0720,iVar5);
      uVar4 = 0xffffffff;
      pcVar8 = local_1a4;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      local_1b4 = 0;
      local_1b0 = 0;
      local_1ac = 0;
      FUN_0040b540(local_1a4,~uVar4 - 1);
      local_4._0_1_ = 1;
      FUN_0044ec30(local_1b8);
      local_4 = (uint)local_4._1_3_ << 8;
      if (local_1b4 != 0) {
        cVar1 = *(char *)(local_1b4 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_1b4 + -1));
        }
        else {
          *(char *)(local_1b4 + -1) = cVar1 + -1;
        }
      }
      local_1b4 = 0;
      local_1b0 = 0;
      local_1ac = 0;
      FUN_0044caa0(local_1a8);
      FUN_0044cf50(iVar5);
      FUN_004afce0(s_adding_char__s_004f073c,local_1a4);
      FUN_0044aaa0(*(undefined4 *)(param_1 + 8),1,local_184);
      FUN_004afce0(s_char_added_004f074c);
      local_4 = 4;
      iVar5 = local_158;
      while (local_158 = iVar5, local_124 != 0) {
        FUN_00438b80();
        iVar5 = local_158;
      }
      local_4._1_3_ = (uint3)((uint)local_4 >> 8);
      local_4._0_1_ = 3;
      for (iVar6 = local_15c; iVar6 != iVar5; iVar6 = iVar6 + 0x60) {
        FUN_0044b410(0);
      }
      FUN_004bc150(local_15c);
      local_15c = 0;
      local_158 = 0;
      local_154 = 0;
      local_4 = CONCAT31(local_4._1_3_,2);
      FUN_0040b4f0(1);
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      iVar7 = iVar7 + 1;
      local_1c4 = local_1c4 + 0x1c;
    } while (iVar7 < *(int *)(param_1 + 0x10));
  }
  ExceptionList = local_c;
  return;
}

