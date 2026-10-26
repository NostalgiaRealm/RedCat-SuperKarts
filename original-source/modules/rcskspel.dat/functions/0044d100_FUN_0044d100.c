/*
 * FUN_0044d100 at 0044d100
 * undefined FUN_0044d100(void)
 * Address ranges: 0044d100-0044d370
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0044d175) */

void __fastcall FUN_0044d100(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined1 local_c4 [4];
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  int local_b4;
  char local_b0 [20];
  undefined1 local_9c [12];
  undefined1 local_90 [20];
  undefined1 local_7c [40];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_1c;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd9db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004bea92(local_90,s__s_d_ini_004f0960,s_ANIMOBJ_004f0958,DAT_0053b9b4);
  FUN_004afce0(s_Animsload_FILE__s_004f096c,local_90);
  FUN_004b1d60(local_90);
  uVar2 = FUN_004b1ed0(s_OBJECTS_004f0988,s_COUNT_004f0980);
  iVar4 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  local_b4 = *(int *)(param_1 + 8);
  iVar5 = iVar4;
  if (iVar4 != local_b4) {
    do {
      FUN_0044e440(0);
      iVar5 = iVar5 + 0x70;
    } while (iVar5 != local_b4);
  }
  *(int *)(param_1 + 8) = iVar4;
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    do {
      FUN_004be8cb(local_9c,10,&DAT_004f0990,iVar4);
      FUN_004afce0(s_Reading_objectanim___d_004f0994,iVar4);
      FUN_004b1f10(s_OBJECTS_004f09ac,local_9c,local_b0,0x14);
      FUN_0044f9a0();
      uVar3 = 0xffffffff;
      pcVar6 = local_b0;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      local_4 = 0;
      local_c0 = 0;
      local_bc = 0;
      local_b8 = 0;
      FUN_0040b540(local_b0,~uVar3 - 1);
      local_4._0_1_ = 1;
      FUN_0044ec30(local_c4);
      local_4 = (uint)local_4._1_3_ << 8;
      if (local_c0 != 0) {
        cVar1 = *(char *)(local_c0 + -1);
        if ((cVar1 == '\0') || (cVar1 == -1)) {
          FUN_004bc150((char *)(local_c0 + -1));
        }
        else {
          *(char *)(local_c0 + -1) = cVar1 + -1;
        }
      }
      local_c0 = 0;
      local_bc = 0;
      local_b8 = 0;
      FUN_004afce0(s_adding_object__s_004f09b4,local_b0);
      FUN_0044db10(*(undefined4 *)(param_1 + 8),1,local_7c);
      FUN_004afce0(s_Object_added_004f09c8);
      local_4 = 4;
      while (local_1c != 0) {
        FUN_00438b80();
      }
      local_4._1_3_ = (uint3)((uint)local_4 >> 8);
      local_4._0_1_ = 3;
      FUN_0044aa50(local_54,local_50);
      FUN_004bc150(local_54);
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_4 = CONCAT31(local_4._1_3_,2);
      FUN_0040b4f0(1);
      local_4 = 0xffffffff;
      FUN_0040b4f0(1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x20));
  }
  ExceptionList = local_c;
  return;
}

