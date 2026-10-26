/*
 * FUN_0043b790 at 0043b790
 * undefined FUN_0043b790(void)
 * Address ranges: 0043b790-0043b8c5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043b790(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  FUN_004371f0();
  cVar7 = FUN_00437550();
  if (cVar7 != '\0') {
    iVar10 = param_1 * 0xd0;
    fVar5 = *(float *)(iVar10 + 0x9c + DAT_0067ee20);
    fVar6 = *(float *)(iVar10 + DAT_0067ee20 + 0xa4);
    uVar8 = __ftol();
    iVar9 = (DAT_004fc8f8 & uVar8) * 4;
    fVar1 = *(float *)(iVar9 + DAT_006a5cd0);
    fVar2 = *(float *)(iVar9 + DAT_006a5c88);
    fVar3 = *(float *)(iVar9 + DAT_006a5c88);
    fVar4 = *(float *)(iVar9 + DAT_006a5cd0);
    FUN_004afce0(s_Handling_sound_source_object__d_004ec310,param_1);
    FUN_0049dd20(*(undefined4 *)(iVar10 + 0x18 + DAT_0067ee20));
    iVar9 = DAT_006a5c38 + *(int *)(iVar10 + 0xc + DAT_0067ee20) * 0xa9;
    FUN_0049da60(*(undefined4 *)(iVar9 + 0x50),*(undefined4 *)(iVar9 + 0x54),
                 *(undefined4 *)(iVar9 + 0x58),fVar1 * fVar5 - fVar2 * fVar6,0,
                 fVar4 * fVar6 + fVar3 * fVar5,param_2);
  }
  return;
}

