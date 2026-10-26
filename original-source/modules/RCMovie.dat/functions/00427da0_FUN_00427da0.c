/*
 * FUN_00427da0 at 00427da0
 * undefined4 __cdecl FUN_00427da0(byte * param_1, char * param_2, void * param_3)
 * Address ranges: 00427da0-00427e4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00427da0(byte *param_1,char *param_2,void *param_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  void *this;
  uint uVar6;
  bool bVar7;
  
  uVar5 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_0043e588 == 0) {
      do {
        bVar2 = *param_1;
        cVar1 = *param_2;
        uVar3 = CONCAT11(bVar2,cVar1);
        if (bVar2 == 0) break;
        uVar3 = CONCAT11(bVar2,cVar1);
        uVar6 = (uint)uVar3;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar6 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
        }
        uVar3 = (ushort)uVar6;
        bVar2 = (byte)uVar6;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar3 = (ushort)CONCAT31((int3)(uVar6 >> 8),bVar2 + 0x20);
        }
        bVar2 = (byte)(uVar3 >> 8);
        bVar7 = bVar2 < (byte)uVar3;
        if (bVar2 != (byte)uVar3) goto LAB_00427dfb;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar5 = 0;
      bVar2 = (byte)(uVar3 >> 8);
      bVar7 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) {
LAB_00427dfb:
        uVar5 = 0xffffffff;
        if (!bVar7) {
          uVar5 = 1;
        }
      }
    }
    else {
      uVar4 = 0;
      uVar6 = 0;
      do {
        uVar4 = CONCAT31((int3)(uVar4 >> 8),*param_1);
        uVar6 = CONCAT31((int3)(uVar6 >> 8),*param_2);
        if ((uVar4 == 0) || (uVar6 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar6 = FUN_004255e3(param_3,uVar6);
        uVar4 = FUN_004255e3(this,uVar4);
        bVar7 = uVar4 < uVar6;
        if (uVar4 != uVar6) goto LAB_00427e3d;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar5 = 0;
      bVar7 = uVar4 < uVar6;
      if (uVar4 != uVar6) {
LAB_00427e3d:
        uVar5 = 0xffffffff;
        if (!bVar7) {
          uVar5 = 1;
        }
      }
    }
  }
  return uVar5;
}

