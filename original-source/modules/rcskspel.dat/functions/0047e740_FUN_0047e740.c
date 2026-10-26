/*
 * FUN_0047e740 at 0047e740
 * undefined FUN_0047e740(void)
 * Address ranges: 0047e740-0047ea1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0047e740(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_8c;
  int local_88 [2];
  undefined1 local_80 [4];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  CRect local_70 [16];
  undefined1 local_60 [20];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [52];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d116a;
  local_c = ExceptionList;
  puVar1 = *(undefined1 **)(param_2 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  ExceptionList = &local_c;
  FUN_004afce0(s__s__d____Enter_InterpreteImageLi_004f8afc,
               s_D__work_rcsk_Code_game_Requester_004f8ad4,0xd8,puVar1,param_3);
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  iVar5 = *(int *)(param_1 + 0x50);
  local_4 = 0;
  piVar2 = (int *)FUN_004802c0(local_88,param_2);
  if (*piVar2 == iVar5) {
    FUN_004afce0(s__s__d____Creating_the_images_004f8ba4,s_D__work_rcsk_Code_game_Requester_004f8b7c
                 ,0xe8);
    iVar5 = 1;
    if (1 < param_3) {
      do {
        FUN_004b2110(iVar5,local_40,0x31);
        iVar3 = FUN_004b2c80(local_40,&local_8c,local_88);
        if (iVar3 == 0) {
          FUN_004afce0(s__s__d____Error_creating_surface_f_004f8bec,
                       s_D__work_rcsk_Code_game_Requester_004f8bc4,0xfa,iVar5,local_40);
        }
        else {
          FUN_004afce0(s__s__d____Adding_image_for__s__wi_004f8c48,
                       s_D__work_rcsk_Code_game_Requester_004f8c20,0x101,local_40,local_8c,
                       local_88[0]);
          local_8c = (DAT_004fe930 * local_8c) / *(int *)(param_1 + 0x44);
          local_88[0] = (DAT_004fe934 * local_88[0]) / *(int *)(param_1 + 0x48);
          uVar4 = CRect::CRect(local_70,0,0,local_8c,local_88[0]);
          uVar4 = FUN_00477a50(iVar3,uVar4);
          FUN_004806b0(local_78,1,uVar4);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_3);
    }
    FUN_004afce0(s__s__d____Adding_the_image_list_004f8ca4,
                 s_D__work_rcsk_Code_game_Requester_004f8c7c,0x10e);
    local_60[0] = *param_2;
    FUN_0040b4f0(0);
    FUN_00412870(param_2,0,0xffffffff);
    local_4._0_1_ = 1;
    FUN_0047d0c0(local_80);
    local_4._0_1_ = 2;
    FUN_00480160(local_88,local_60);
    local_4._0_1_ = 3;
    FUN_0048b600(local_4c,local_48);
    FUN_004bc150(local_4c);
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0040b4f0(1);
    FUN_004afce0(s__s__d____Done_adding_the_image_l_004f8cec,
                 s_D__work_rcsk_Code_game_Requester_004f8cc4,0x110);
  }
  else {
    puVar1 = *(undefined1 **)(param_2 + 4);
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_004d2404;
    }
    FUN_004afce0(s__s__d____Image_list__s_already_a_004f8b50,
                 s_D__work_rcsk_Code_game_Requester_004f8b28,0xe3,puVar1);
  }
  FUN_004afce0(s__s__d____m_ImageList_contains__d_004f8d3c,
               s_D__work_rcsk_Code_game_Requester_004f8d14,0x114,*(undefined4 *)(param_1 + 0x58));
  puVar1 = *(undefined1 **)(param_2 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afce0(s__s__d____Leave_InterpreteImageLi_004f8d94,
               s_D__work_rcsk_Code_game_Requester_004f8d6c,0x118,puVar1,param_3);
  FUN_004bc150(local_7c);
  ExceptionList = local_c;
  return;
}

