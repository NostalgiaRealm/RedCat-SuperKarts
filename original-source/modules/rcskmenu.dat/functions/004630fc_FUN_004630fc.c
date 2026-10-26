/*
 * FUN_004630fc at 004630fc
 * undefined __register FUN_004630fc(int * param_1)
 * Address ranges: 004630fc-00463d86
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004630fc(int *param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_190;
  int local_18c;
  POINT PStack_180;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  LONG LStack_120;
  LONG LStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  POINT PStack_c0;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  POINT PStack_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  RECT RStack_20;
  
  FUN_00463e4c(param_1,&local_190);
  cVar3 = (**(code **)(*param_1 + 0x4c))();
  if (cVar3 == '\0') {
    FUN_00417ea0(*(int **)(param_1[0x83] + 0x14),*(undefined4 *)(param_1[0x80] + 8));
  }
  else {
    FUN_00417ea0(*(int **)(param_1[0x83] + 0x14),param_1[0x81]);
  }
  uVar4 = FUN_00417bb4(*(int *)(param_1[0x83] + 0x10));
  if ((char)param_1[0x4e] == '\0') {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),*(undefined4 *)(param_1[0x80] + 0x18));
  }
  else {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),*(undefined4 *)(param_1[0x80] + 0xc));
  }
  iVar2 = local_18c;
  iVar1 = local_190;
  FUN_0040ebd0(local_190 + 9,local_18c + 1,&LStack_120);
  PStack_180.x = LStack_120;
  PStack_180.y = LStack_11c;
  FUN_0040ebd0(iVar1 + 8,local_18c + 1,&uStack_118);
  uStack_178 = uStack_118;
  uStack_174 = uStack_114;
  FUN_0040ebd0(iVar1 + 7,iVar2,&uStack_110);
  uStack_170 = uStack_110;
  uStack_16c = uStack_10c;
  FUN_0040ebd0(iVar1 + 4,iVar2,&uStack_108);
  uStack_168 = uStack_108;
  uStack_164 = uStack_104;
  FUN_0040ebd0(iVar1 + 3,local_18c + 1,&uStack_100);
  uStack_160 = uStack_100;
  uStack_15c = uStack_fc;
  FUN_0040ebd0(iVar1 + 2,local_18c + 1,&uStack_f8);
  uStack_158 = uStack_f8;
  uStack_154 = uStack_f4;
  FUN_0040ebd0(iVar1 + 1,iVar2 + 2,&uStack_f0);
  uStack_150 = uStack_f0;
  uStack_14c = uStack_ec;
  FUN_0040ebd0(local_190 + 1,iVar2 + 3,&uStack_e8);
  uStack_148 = uStack_e8;
  uStack_144 = uStack_e4;
  FUN_0040ebd0(iVar1,iVar2 + 4,&uStack_e0);
  uStack_140 = uStack_e0;
  uStack_13c = uStack_dc;
  FUN_0040ebd0(iVar1,iVar2 + 7,&uStack_d8);
  uStack_138 = uStack_d8;
  uStack_134 = uStack_d4;
  FUN_0040ebd0(local_190 + 1,iVar2 + 8,&uStack_d0);
  uStack_130 = uStack_d0;
  uStack_12c = uStack_cc;
  FUN_0040ebd0(local_190 + 1,iVar2 + 10,&uStack_c8);
  uStack_128 = uStack_c8;
  uStack_124 = uStack_c4;
  FUN_0041863c((int *)param_1[0x83],&PStack_180,0xb);
  if ((char)param_1[0x4e] == '\0') {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),param_1[0x81]);
  }
  else {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),*(undefined4 *)(param_1[0x80] + 0x14));
  }
  FUN_0040ebd0(local_190 + 2,iVar2 + 9,&LStack_120);
  PStack_c0.x = LStack_120;
  PStack_c0.y = LStack_11c;
  FUN_0040ebd0(local_190 + 3,local_18c + 9,&uStack_118);
  uStack_b8 = uStack_118;
  uStack_b4 = uStack_114;
  FUN_0040ebd0(local_190 + 4,local_18c + 10,&uStack_110);
  uStack_b0 = uStack_110;
  uStack_ac = uStack_10c;
  FUN_0040ebd0(local_190 + 7,local_18c + 10,&uStack_108);
  uStack_a8 = uStack_108;
  uStack_a4 = uStack_104;
  FUN_0040ebd0(local_190 + 8,local_18c + 9,&uStack_100);
  uStack_a0 = uStack_100;
  uStack_9c = uStack_fc;
  FUN_0040ebd0(local_190 + 9,local_18c + 9,&uStack_f8);
  uStack_98 = uStack_f8;
  uStack_94 = uStack_f4;
  FUN_0040ebd0(local_190 + 9,local_18c + 8,&uStack_f0);
  uStack_90 = uStack_f0;
  uStack_8c = uStack_ec;
  FUN_0040ebd0(iVar1 + 10,local_18c + 7,&uStack_e8);
  uStack_88 = uStack_e8;
  uStack_84 = uStack_e4;
  FUN_0040ebd0(local_190 + 10,local_18c + 4,&uStack_e0);
  uStack_80 = uStack_e0;
  uStack_7c = uStack_dc;
  FUN_0040ebd0(local_190 + 9,local_18c + 3,&uStack_d8);
  uStack_78 = uStack_d8;
  uStack_74 = uStack_d4;
  FUN_0040ebd0(local_190 + 10,local_18c + 4,&uStack_d0);
  uStack_70 = uStack_d0;
  uStack_6c = uStack_cc;
  FUN_0041863c((int *)param_1[0x83],&PStack_c0,10);
  if ((char)param_1[0x4e] == '\0') {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),*(undefined4 *)(param_1[0x80] + 0x18));
  }
  else {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),*(undefined4 *)(param_1[0x80] + 0x10));
  }
  FUN_0040ebd0(local_190 + 10,local_18c + 2,&LStack_120);
  PStack_180.x = LStack_120;
  PStack_180.y = LStack_11c;
  FUN_0040ebd0(local_190 + 10,local_18c + 3,&uStack_118);
  uStack_178 = uStack_118;
  uStack_174 = uStack_114;
  FUN_0040ebd0(iVar1 + 0xb,local_18c + 4,&uStack_110);
  uStack_170 = uStack_110;
  uStack_16c = uStack_10c;
  FUN_0040ebd0(local_190 + 0xb,local_18c + 7,&uStack_108);
  uStack_168 = uStack_108;
  uStack_164 = uStack_104;
  FUN_0040ebd0(local_190 + 10,local_18c + 8,&uStack_100);
  uStack_160 = uStack_100;
  uStack_15c = uStack_fc;
  FUN_0040ebd0(local_190 + 10,local_18c + 9,&uStack_f8);
  uStack_158 = uStack_f8;
  uStack_154 = uStack_f4;
  FUN_0040ebd0(local_190 + 9,local_18c + 10,&uStack_f0);
  uStack_150 = uStack_f0;
  uStack_14c = uStack_ec;
  FUN_0040ebd0(local_190 + 8,local_18c + 10,&uStack_e8);
  uStack_148 = uStack_e8;
  uStack_144 = uStack_e4;
  FUN_0040ebd0(local_190 + 7,iVar2 + 0xb,&uStack_e0);
  uStack_140 = uStack_e0;
  uStack_13c = uStack_dc;
  FUN_0040ebd0(local_190 + 4,iVar2 + 0xb,&uStack_d8);
  uStack_138 = uStack_d8;
  uStack_134 = uStack_d4;
  FUN_0040ebd0(local_190 + 3,local_18c + 10,&uStack_d0);
  uStack_130 = uStack_d0;
  uStack_12c = uStack_cc;
  FUN_0040ebd0(local_190 + 1,local_18c + 10,&uStack_c8);
  uStack_128 = uStack_c8;
  uStack_124 = uStack_c4;
  FUN_0041863c((int *)param_1[0x83],&PStack_180,0xb);
  if ((char)param_1[0x4e] == '\0') {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),param_1[0x81]);
  }
  else {
    FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),*(undefined4 *)(param_1[0x80] + 0x18));
  }
  FUN_0040ebd0(local_190 + 9,local_18c + 2,&LStack_120);
  PStack_c0.x = LStack_120;
  PStack_c0.y = LStack_11c;
  FUN_0040ebd0(local_190 + 8,local_18c + 2,&uStack_118);
  uStack_b8 = uStack_118;
  uStack_b4 = uStack_114;
  FUN_0040ebd0(local_190 + 7,local_18c + 1,&uStack_110);
  uStack_b0 = uStack_110;
  uStack_ac = uStack_10c;
  FUN_0040ebd0(local_190 + 4,local_18c + 1,&uStack_108);
  uStack_a8 = uStack_108;
  uStack_a4 = uStack_104;
  FUN_0040ebd0(local_190 + 3,local_18c + 2,&uStack_100);
  uStack_a0 = uStack_100;
  uStack_9c = uStack_fc;
  FUN_0040ebd0(local_190 + 2,local_18c + 2,&uStack_f8);
  uStack_98 = uStack_f8;
  uStack_94 = uStack_f4;
  FUN_0040ebd0(local_190 + 2,local_18c + 3,&uStack_f0);
  uStack_90 = uStack_f0;
  uStack_8c = uStack_ec;
  FUN_0040ebd0(local_190 + 1,local_18c + 4,&uStack_e8);
  uStack_88 = uStack_e8;
  uStack_84 = uStack_e4;
  FUN_0040ebd0(local_190 + 1,local_18c + 7,&uStack_e0);
  uStack_80 = uStack_e0;
  uStack_7c = uStack_dc;
  FUN_0040ebd0(local_190 + 2,local_18c + 8,&uStack_d8);
  uStack_78 = uStack_d8;
  uStack_74 = uStack_d4;
  FUN_0040ebd0(local_190 + 1,local_18c + 7,&uStack_d0);
  uStack_70 = uStack_d0;
  uStack_6c = uStack_cc;
  FUN_0041863c((int *)param_1[0x83],&PStack_c0,10);
  uVar5 = FUN_00417e98(*(int *)(param_1[0x83] + 0x14));
  FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),uVar5);
  FUN_0040ebd0(local_190 + 7,local_18c + 2,&LStack_120);
  PStack_68.x = LStack_120;
  PStack_68.y = LStack_11c;
  FUN_0040ebd0(local_190 + 4,local_18c + 2,&uStack_118);
  uStack_60 = uStack_118;
  uStack_5c = uStack_114;
  FUN_0040ebd0(local_190 + 2,local_18c + 4,&uStack_110);
  uStack_58 = uStack_110;
  uStack_54 = uStack_10c;
  FUN_0040ebd0(local_190 + 2,local_18c + 7,&uStack_108);
  uStack_50 = uStack_108;
  uStack_4c = uStack_104;
  FUN_0040ebd0(local_190 + 4,local_18c + 9,&uStack_100);
  uStack_48 = uStack_100;
  uStack_44 = uStack_fc;
  FUN_0040ebd0(local_190 + 7,local_18c + 9,&uStack_f8);
  uStack_40 = uStack_f8;
  uStack_3c = uStack_f4;
  FUN_0040ebd0(local_190 + 9,local_18c + 7,&uStack_f0);
  uStack_38 = uStack_f0;
  uStack_34 = uStack_ec;
  FUN_0040ebd0(local_190 + 9,local_18c + 4,&uStack_e8);
  uStack_30 = uStack_e8;
  uStack_2c = uStack_e4;
  FUN_0040ebd0(local_190 + 7,local_18c + 2,&uStack_e0);
  uStack_28 = uStack_e0;
  uStack_24 = uStack_dc;
  FUN_0041863c((int *)param_1[0x83],&PStack_68,8);
  FUN_0040ebe8(local_190 + 3,local_18c + 3,local_190 + 9,&RStack_20.left,local_18c + 9);
  FUN_00418538((int *)param_1[0x83],&RStack_20);
  FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),uVar4);
  if ((char)param_1[0x84] != '\0') {
    FUN_00464060(param_1);
  }
  return;
}

