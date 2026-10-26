/*
 * FUN_00473820 at 00473820
 * undefined FUN_00473820(void)
 * Address ranges: 00473820-004739a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00473820(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  FUN_004707f0();
  FUN_004afce0(s___Initializing_mouse_004f7510);
  iVar1 = FUN_00471560(0xb);
  uVar7 = *(undefined4 *)(iVar1 + 4);
  puVar2 = (undefined4 *)FUN_00471560(0xb);
  uVar6 = *puVar2;
  uVar3 = FUN_00471520(0xb);
  FUN_00471ae0(uVar3,uVar6,uVar7);
  FUN_004afce0(s___Initializing_form_004f7528);
  FUN_004739b0();
  FUN_004b0e90(0,0);
  FUN_004b0e90(1,0);
  FUN_004b0e90(2,0);
  FUN_004afce0(s___Loading_form_background_004f7540);
  FUN_004715e0(2,0,9);
  FUN_004715e0(2,1,9);
  FUN_004715e0(2,3,9);
  FUN_004715e0(2,5,9);
  FUN_004715e0(2,8,9);
  FUN_004afce0(s___Updating_back_screen_004f755c);
  FUN_004b0c70();
  FUN_004afce0(s___Starting_menu_004f7574);
  FUN_004afce0(s___Setting_mouse_on_no_button_004f7588);
  iVar1 = FUN_00471560(8);
  iVar1 = *(int *)(iVar1 + 4);
  iVar4 = FUN_004715a0(8);
  iVar4 = iVar1 / 2 + *(int *)(iVar4 + 4);
  piVar5 = (int *)FUN_00471560(8);
  iVar1 = *piVar5;
  piVar5 = (int *)FUN_004715a0(8);
  FUN_004b9e40(iVar1 / 2 + *piVar5,iVar4);
  FUN_004afce0(s___Hiding_mouse_004f75a8);
  iVar1 = FUN_004b3830(0x1b);
  while (iVar1 != 0) {
    FUN_00473d40();
    iVar1 = FUN_004b3830(0x1b);
  }
  FUN_004afce0(s___Rendering_screen_004f75b8);
  FUN_004739c0(&local_4);
  FUN_004afce0(s___Flipping_page_004f75cc);
  FUN_004aff70();
  FUN_004afce0(s___Returning_from_open_stoppen___004f75e0);
  return 0;
}

