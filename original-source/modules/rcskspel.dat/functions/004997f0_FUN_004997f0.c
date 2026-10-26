/*
 * FUN_004997f0 at 004997f0
 * undefined FUN_004997f0(void)
 * Address ranges: 004997f0-004999b5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004997f0(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = *(int *)(DAT_00680b28 + 0xf4 + param_2 * 4 + param_1 * 0x984) * 0x60;
  fVar1 = *(float *)(iVar6 + 0x5c + DAT_006a5be8);
  if (199 < DAT_006847c8) {
    FUN_004afee0(s__s__d____Max_nb_of_bboxs_reached_004fb7c0,
                 s_D__work_rcsk_Code_Engine_Prog_Bb_004fb7e4,0x57);
  }
  iVar2 = DAT_006847c8;
  iVar3 = DAT_006847c8 * 0x4c;
  *(undefined4 *)(&DAT_00680c68 + iVar3) = 0xc1200000;
  *(undefined4 *)(&DAT_00680c6c + iVar3) = 0;
  fVar1 = fVar1 + 1.0;
  *(undefined4 *)(&DAT_00680c70 + iVar3) = 0xbf800000;
  *(undefined4 *)(&DAT_00680c74 + iVar3) = 0;
  *(undefined4 *)(&DAT_00680c78 + iVar3) = 0;
  *(undefined4 *)(&DAT_00680c7c + iVar3) = 0xbf800000;
  *(undefined4 *)(&DAT_00680c80 + iVar3) = 0;
  *(undefined4 *)(&DAT_00680c84 + iVar3) = 0;
  *(float *)(&DAT_00680c88 + iVar3) = fVar1;
  *(undefined4 *)(&DAT_00680c8c + iVar3) = 0xc1200000;
  *(undefined4 *)(&DAT_00680c90 + iVar3) = 0;
  *(float *)(&DAT_00680c94 + iVar3) = fVar1;
  puVar5 = (undefined4 *)(DAT_006a5be8 + iVar6);
  *(undefined4 *)(&DAT_00680c98 + iVar3) = *puVar5;
  *(undefined4 *)(&DAT_00680c9c + iVar3) = puVar5[1];
  *(undefined4 *)(&DAT_00680ca0 + iVar3) = puVar5[2];
  if ((float)puVar5[6] <= 0.0) {
    FUN_004c062b((double)(float)puVar5[6]);
  }
  else {
    FUN_004c06fa((double)(float)puVar5[6]);
  }
  uVar4 = __ftol();
  (&DAT_00680cac)[iVar2 * 0x13] = uVar4;
  *(undefined4 *)(&DAT_00680ca4 + iVar2 * 0x4c) = 0;
  (&DAT_00680ca8)[iVar2 * 0x13] = 0xffffffff;
  *(undefined4 *)(&DAT_00680cb0 + iVar2 * 0x4c) = 0;
  DAT_006847c8 = DAT_006847c8 + 1;
  return;
}

