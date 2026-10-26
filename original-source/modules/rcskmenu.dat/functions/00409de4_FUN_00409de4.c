/*
 * FUN_00409de4 at 00409de4
 * undefined __register FUN_00409de4(int param_1, int * param_2, double * param_3)
 * Address ranges: 00409de4-0040a044;0040a047-0040a0f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409de4(int param_1,int *param_2,double *param_3)

{
  bool bVar1;
  WORD WVar2;
  undefined4 uVar3;
  PCNZCH pCVar4;
  undefined2 extraout_var;
  int iVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ushort uVar7;
  uint uVar8;
  undefined4 *in_FS_OFFSET;
  undefined **ppuVar9;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  undefined *local_2c;
  undefined *local_28;
  int local_24;
  undefined *local_20;
  byte local_1c;
  byte local_1b;
  char local_1a;
  byte local_19;
  ushort local_18;
  ushort local_16;
  ushort local_14;
  ushort local_12;
  ushort local_10;
  char local_e;
  undefined1 local_d;
  double *local_c;
  int local_8;
  
  puStack_3c = &stack0xfffffffc;
  local_2c = (undefined *)0x0;
  local_28 = (undefined *)0x0;
  local_24 = 0;
  local_20 = (undefined *)0x0;
  puStack_40 = &LAB_0040a0f6;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  uVar8 = 0;
  local_16 = 0;
  local_18 = 0;
  local_1c = 0;
  local_d = 0;
  local_c = param_3;
  uVar3 = FUN_00409cac((int)DAT_0047d4fc);
  local_e = (char)uVar3;
  local_8 = 0;
  if (*DAT_0047d4fc == 'g') {
    FUN_00409cf8(param_1,param_2);
    FUN_00403fd8(param_1,1,*param_2 - 1,&local_24);
    FUN_00407e44(local_24,(int *)&local_20);
    local_8 = FUN_00409d34(local_20);
  }
  else {
    pCVar4 = FUN_0040b75c(&DAT_0040a110,DAT_0047d4fc);
    if (0 < (int)pCVar4) {
      local_8 = DAT_0047d5d8;
    }
  }
  bVar1 = FUN_00409b54(param_1,param_2,&local_10,(char *)&local_19);
  if (((bVar1) && (uVar3 = FUN_00409c74(param_1,param_2,DAT_0047d4f9), (char)uVar3 != '\0')) &&
     (bVar1 = FUN_00409b54(param_1,param_2,&local_12,&local_1a), bVar1)) {
    uVar3 = FUN_00409c74(param_1,param_2,DAT_0047d4f9);
    if ((char)uVar3 == '\0') {
      WVar2 = FUN_00408f40();
      uVar8 = CONCAT22(extraout_var,WVar2);
      if (local_e == '\x01') {
        local_18 = local_10;
        local_16 = local_12;
      }
      else {
        local_16 = local_10;
        local_18 = local_12;
      }
    }
    else {
      bVar1 = FUN_00409b54(param_1,param_2,&local_14,(char *)&local_1b);
      if (!bVar1) goto LAB_0040a0db;
      if (local_e == '\0') {
        uVar8 = (uint)local_14;
        local_1c = local_1b;
        local_16 = local_10;
        local_18 = local_12;
      }
      else if (local_e == '\x01') {
        uVar8 = (uint)local_14;
        local_1c = local_1b;
        local_16 = local_12;
        local_18 = local_10;
      }
      else if (local_e == '\x02') {
        uVar8 = (uint)local_10;
        local_1c = local_19;
        local_16 = local_12;
        local_18 = local_14;
      }
      if (local_8 < 1) {
        if (local_1c < 3) {
          WVar2 = FUN_00408f40();
          uVar7 = (short)uVar8 + (short)((int)((uint)WVar2 - (uint)DAT_0047b0e0) / 100) * 100;
          uVar8 = (uint)uVar7;
          if ((DAT_0047b0e0 != 0) && ((int)(uint)uVar7 < (int)((uint)WVar2 - (uint)DAT_0047b0e0))) {
            uVar8 = (uint)(ushort)(uVar7 + 100);
          }
        }
      }
      else {
        uVar8 = FUN_00409d88(uVar8,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
      }
    }
    FUN_00409c74(param_1,param_2,DAT_0047d4f9);
    FUN_00409b30(param_1,param_2);
    if ((DAT_0047d5b8 != '\0') && (iVar5 = FUN_004040bc("ddd",DAT_0047d4fc), iVar5 != 0)) {
      if ((byte)(*DAT_0047d510 - 0x30U) < 10) {
        FUN_00409cf8(param_1,param_2);
      }
      else {
        do {
          while ((iVar5 = FUN_00403dd0(param_1), *param_2 <= iVar5 &&
                 (*(char *)(param_1 + -1 + *param_2) != ' '))) {
            *param_2 = *param_2 + 1;
          }
          FUN_00409b30(param_1,param_2);
          iVar5 = FUN_00403dd0(param_1);
          if (iVar5 < *param_2) break;
          ppuVar9 = &local_28;
          uVar6 = FUN_00403dd0((int)DAT_0047d508);
          FUN_00403fd8(param_1,*param_2,uVar6,(int *)ppuVar9);
          iVar5 = FUN_00407db0(DAT_0047d508,local_28);
          if (iVar5 == 0) break;
          ppuVar9 = &local_2c;
          uVar6 = FUN_00403dd0((int)DAT_0047d50c);
          FUN_00403fd8(param_1,*param_2,uVar6,(int *)ppuVar9);
          iVar5 = FUN_00407db0(DAT_0047d50c,local_2c);
        } while (iVar5 != 0);
      }
    }
    local_d = FUN_00408cec(uVar8,local_16,local_18,local_c);
  }
LAB_0040a0db:
  *in_FS_OFFSET = uStack_44;
  puStack_3c = &LAB_0040a0fd;
  puStack_40 = (undefined1 *)0x40a0f5;
  FUN_00403b74((int *)&local_2c,4);
  return;
}

