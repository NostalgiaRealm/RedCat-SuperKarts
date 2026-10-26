/*
 * FUN_00403543 at 00403543
 * undefined FUN_00403543(void)
 * Address ranges: 00403543-004036a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00403543(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint unaff_EBX;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  int iStack00000100;
  uint in_stack_00000104;
  ushort *in_stack_00000108;
  int in_stack_0000010c;
  uint in_stack_00000110;
  uint in_stack_00000114;
  uint in_stack_00000118;
  undefined1 in_stack_0000011c;
  byte in_stack_00000120;
  int in_stack_00000138;
  uint in_stack_00000140;
  
  iVar4 = unaff_EBX * unaff_EDI;
  iVar2 = (param_1 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 2 + iVar4) >> 2);
  iVar3 = (param_1 >> 8 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 1 + iVar4) >> 2);
  iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
  iVar2 = (uint)in_stack_00000120 - ((int)(uint)*(byte *)(unaff_ESI + iVar4) >> 2);
  uVar1 = iVar2 * iVar2 + iStack00000100;
  do {
    if (uVar1 < in_stack_00000114) {
      in_stack_0000011c = (undefined1)unaff_EBX;
      in_stack_00000114 = uVar1;
      if (uVar1 != 0) goto LAB_0040362d;
LAB_00403656:
      do {
        (&stack0x00000000)[in_stack_00000104] = in_stack_0000011c;
        unaff_EBX = in_stack_00000104 + 1;
        if (0xff < unaff_EBX) {
          FUN_0040d660(*(int **)(in_stack_00000138 + 0x39c),&stack0x00000000);
          return;
        }
        in_stack_00000114 = 0xffffffff;
        in_stack_00000120 = (byte)in_stack_00000108[1];
        param_1 = (uint)*in_stack_00000108;
        in_stack_00000108 = (ushort *)((int)in_stack_00000108 + 3);
        in_stack_00000118 = 0;
        in_stack_00000104 = unaff_EBX;
      } while (in_stack_00000140 == 0);
    }
    else {
LAB_0040362d:
      unaff_EBX = unaff_EBX + 1;
      if (unaff_EBX == 0x100) {
        unaff_EBX = 0;
      }
      in_stack_00000118 = in_stack_00000118 + 1;
      if (in_stack_00000140 <= in_stack_00000118) goto LAB_00403656;
    }
    if (in_stack_00000110 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00403443. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((int)&PTR_FUN_00403320 + in_stack_0000010c))();
      return;
    }
    iVar4 = unaff_EBX * unaff_EDI;
    iVar2 = (param_1 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 2 + iVar4) >> 2);
    iVar3 = (param_1 >> 8 & 0xff) - ((int)(uint)*(byte *)(unaff_ESI + 4 + iVar4) >> 2);
    iStack00000100 = iVar2 * iVar2 + iVar3 * iVar3;
    iVar2 = (uint)in_stack_00000120 - ((int)(uint)*(byte *)(unaff_ESI + 6 + iVar4) >> 2);
    uVar1 = iVar2 * iVar2 + iStack00000100;
  } while( true );
}

