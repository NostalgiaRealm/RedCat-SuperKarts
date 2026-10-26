/*
 * FUN_00407d04 at 00407d04
 * int __register FUN_00407d04(char * param_1, char * param_2)
 * Address ranges: 00407d04-00407d56
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00407d04(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  bool bVar8;
  
  uVar3 = 0;
  if (param_1 != (char *)0x0) {
    uVar3 = *(uint *)(param_1 + -4);
  }
  uVar5 = 0;
  if (param_2 != (char *)0x0) {
    uVar5 = *(uint *)(param_2 + -4);
  }
  uVar4 = uVar3;
  if (uVar5 < uVar3) {
    uVar4 = uVar5;
  }
  bVar8 = true;
LAB_00407d23:
  do {
    if (uVar4 != 0) {
      uVar4 = uVar4 - 1;
      pcVar2 = param_2 + 1;
      pcVar1 = param_1 + 1;
      bVar8 = *param_1 == *param_2;
      param_1 = pcVar1;
      param_2 = pcVar2;
      if (bVar8) goto LAB_00407d23;
    }
    if (bVar8) goto LAB_00407d51;
    bVar6 = param_1[-1];
    if ((0x60 < bVar6) && (bVar6 < 0x7b)) {
      bVar6 = bVar6 - 0x20;
    }
    bVar7 = param_2[-1];
    if ((0x60 < bVar7) && (bVar7 < 0x7b)) {
      bVar7 = bVar7 - 0x20;
    }
    bVar8 = bVar6 == bVar7;
    if (!bVar8) {
      uVar3 = (uint)bVar6;
      uVar5 = (uint)bVar7;
LAB_00407d51:
      return uVar3 - uVar5;
    }
  } while( true );
}

