/*
 * Catch@0045d600 at 0045d600
 * undefined Catch@0045d600(void)
 * Address ranges: 0045d600-0045d7ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void Catch_0045d600(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_EBP;
  char *pcVar5;
  
  *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(unaff_EBP + 0xb);
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = *(char **)(unaff_EBP + 8);
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(*(char **)(unaff_EBP + 8),~uVar4 - 1);
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  *(undefined1 *)(unaff_EBP + -0x60) = *(undefined1 *)(unaff_EBP + 0xb);
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_Incorrect_X_Y_Z_values_in_ReadXY_004f3320;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_Incorrect_X_Y_Z_values_in_ReadXY_004f3320,~uVar4 - 1);
  *(undefined1 *)(unaff_EBP + -0x80) = *(undefined1 *)(unaff_EBP + 0xb);
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = &DAT_004f3344;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f3344,~uVar4 - 1);
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  uVar2 = FUN_00463d20(unaff_EBP + -0x128,0x293);
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  *(undefined1 *)(unaff_EBP + -0x90) = *(undefined1 *)(unaff_EBP + 0xb);
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_D__work_rcsk_Code_game_Hud_IniFi_004f334c;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_D__work_rcsk_Code_game_Hud_IniFi_004f334c,~uVar4 - 1);
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  *(undefined1 *)(unaff_EBP + -0x40) = *(undefined1 *)(unaff_EBP + 0xb);
  FUN_0040b4f0(0);
  uVar4 = 0xffffffff;
  pcVar5 = s_HeadUp_Display_exception_in__004f3378;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(s_HeadUp_Display_exception_in__004f3378,~uVar4 - 1);
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  uVar3 = FUN_00459040(unaff_EBP + -0x1d8,unaff_EBP + -0x40,unaff_EBP + -0x90);
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  uVar3 = FUN_0041b630(unaff_EBP + -0x1f8,uVar3,&DAT_004f3348);
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  uVar2 = FUN_00459040(unaff_EBP + -0x1e8,uVar3,uVar2);
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  uVar2 = FUN_00459040(unaff_EBP + -0x108,uVar2,unaff_EBP + -0x80);
  *(undefined1 *)(unaff_EBP + -4) = 0x19;
  uVar2 = FUN_00459040(unaff_EBP + -0x188,uVar2,unaff_EBP + -0x60);
  *(undefined1 *)(unaff_EBP + -4) = 0x1a;
  uVar2 = FUN_00459040(unaff_EBP + -0xd8,uVar2,unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -4) = 0x1b;
  uVar2 = FUN_0041b630(unaff_EBP + -0x1c8,uVar2,&DAT_004f331c);
  *(undefined1 *)(unaff_EBP + -4) = 0x1c;
  FUN_00459dc0(uVar2);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -200,&DAT_004d6580);
}

