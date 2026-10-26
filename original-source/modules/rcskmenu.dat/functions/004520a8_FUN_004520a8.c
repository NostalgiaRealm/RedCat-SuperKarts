/*
 * FUN_004520a8 at 004520a8
 * undefined FUN_004520a8(void)
 * Address ranges: 004520a8-004520cf;0045213f-0045215c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Instruction at (ram,0x00452143) overlaps instruction at (ram,0x00452142)
    */

int * FUN_004520a8(uint param_1,ushort param_2,uint *param_3,undefined4 param_4,undefined4 param_5,
                  undefined4 param_6,HGLOBAL param_7,int *param_8)

{
  byte *pbVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  SIZE_T SVar5;
  LPVOID pvVar6;
  int *piVar7;
  HGLOBAL extraout_ECX;
  undefined4 extraout_EDX;
  byte bVar8;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  undefined4 *in_FS_OFFSET;
  byte in_CF;
  undefined4 in_stack_00000000;
  undefined4 uVar9;
  
  uVar9 = 0xa000411c;
  bVar8 = (byte)unaff_EBX;
  DAT_1bd80041 = (DAT_1bd80041 - bVar8) - (param_1 < *param_3 || param_1 - *param_3 < (uint)in_CF);
  pbVar1 = &stack0x5413003d + (int)unaff_EBX;
  bVar2 = *pbVar1;
  *pbVar1 = *pbVar1 + (byte)param_2;
  uVar3 = in(param_2);
  *(undefined1 *)(unaff_EDI + 1) = uVar3;
  out(*unaff_ESI,param_2);
  uVar4 = in(param_2);
  *(undefined4 *)(unaff_EDI + 2) = uVar4;
  out(unaff_ESI[1],param_2);
  if (CARRY1(bVar2,(byte)param_2)) {
    param_2 = (ushort)(bVar8 & 0xfc);
  }
  else if (unaff_EBP != 1) {
    uVar4 = in((short)param_6);
    *unaff_EBX = uVar4;
    if ((char)param_6 != '\0') {
      param_8 = (int *)FUN_004031ac((int)param_8,(char)param_6,param_7,0xa000411c,in_stack_00000000)
      ;
      param_7 = extraout_ECX;
      param_6 = extraout_EDX;
    }
    FUN_00402e7c(param_8,'\0',param_7);
    param_8[5] = (int)param_7;
    SVar5 = GlobalSize(param_7);
    pvVar6 = GlobalLock(param_7);
    FUN_00411b98((int)param_8,pvVar6,SVar5);
    if ((char)param_6 != '\0') {
      FUN_00403204(param_8);
      *in_FS_OFFSET = uVar9;
    }
    return param_8;
  }
  *(int *)((int)unaff_EBX + -0x31d7f2d) = *(int *)((int)unaff_EBX + -0x31d7f2d) + -1;
  piVar7 = (int *)FUN_00411bfc(unaff_ESI + 2,(char)param_2);
  if ('\0' < (char)bVar8) {
    piVar7 = (int *)FUN_004031fc(unaff_ESI + 2);
  }
  return piVar7;
}

