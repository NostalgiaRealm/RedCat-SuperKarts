/*
 * FUN_00446c00 at 00446c00
 * undefined FUN_00446c00(void)
 * Address ranges: 00446c00-00446dca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00446c9b) */

undefined4 FUN_00446c00(int param_1)

{
  uint uVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *local_4c;
  char *local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined1 local_20 [12];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  undefined1 local_4;
  undefined1 local_3;
  
  local_40 = (undefined1 *)(&DAT_0053f668)[param_1 * 0xd0];
  local_44 = 0x446c24;
  cVar2 = FUN_00446b80();
  if (cVar2 == '\0') {
    local_40 = (undefined1 *)(&DAT_0053f668)[param_1 * 0xd0];
    local_44 = 0x288;
    local_48 = s_D__work_rcsk_Code_game_pth_PathC_004efb4c;
    local_4c = s__s__d____Unsupported_path_type___004efb7c;
    FUN_004afee0();
    return 0;
  }
  local_40 = (undefined1 *)(&DAT_0053f668)[param_1 * 0xd0];
  local_44 = 0x446c5f;
  FUN_00446170();
  local_44 = 0x446c66;
  FUN_004461e0();
  local_40 = (undefined1 *)0x446c71;
  puVar3 = (undefined1 *)FUN_00445e00();
  local_4c = (char *)CONCAT31(local_4c._1_3_,*puVar3);
  local_48 = (char *)0x0;
  local_44 = 0;
  local_40 = (undefined1 *)0x0;
  uVar1 = *(uint *)(puVar3 + 8);
  if (&local_4c == (char **)puVar3) {
    FUN_004478a0(uVar1,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar1 != 0) {
      puVar4 = *(undefined1 **)(puVar3 + 4);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        FUN_0040b4f0(1);
        local_48 = *(char **)(puVar3 + 4);
        if (local_48 == (char *)0x0) {
          local_48 = &DAT_004d2404;
        }
        local_44 = *(undefined4 *)(puVar3 + 8);
        local_40 = *(undefined1 **)(puVar3 + 0xc);
        *(char *)((int)local_48 + -1) = *(char *)((int)local_48 + -1) + '\x01';
        goto LAB_00446d3b;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar7 = *(undefined4 **)(puVar3 + 4);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)&DAT_004d2404;
      }
      pcVar8 = local_48;
      for (uVar6 = uVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        pcVar8 = (char *)((int)pcVar8 + 4);
      }
      for (uVar6 = uVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar8 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        pcVar8 = (char *)((int)pcVar8 + 1);
      }
      FUN_0040b5e0(uVar1);
    }
  }
LAB_00446d3b:
  local_40 = (undefined1 *)FUN_0044d4d0();
  local_44 = 0x446d50;
  FUN_0044d4b0();
  local_40 = (undefined1 *)0x446d57;
  iVar5 = FUN_0044f9d0();
  (&DAT_0053f99c)[param_1 * 0xd0] = iVar5;
  *(undefined4 *)(iVar5 * 0xd0 + 0x44 + DAT_0067ee20) = 1;
  local_10 = (&DAT_0053f99c)[param_1 * 0xd0];
  local_20[0] = 1;
  local_14 = 0x3f000000;
  local_c = 0xffffffff;
  local_8 = param_1;
  local_40 = (undefined1 *)0x446da5;
  local_4 = FUN_00445e10();
  local_40 = (undefined1 *)0x446db0;
  local_3 = FUN_00445e20();
  local_40 = local_20;
  local_44 = 0x446dbe;
  FUN_00445740();
  return 1;
}

