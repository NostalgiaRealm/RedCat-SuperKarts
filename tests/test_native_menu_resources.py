import importlib.util
from pathlib import Path
import unittest
SPEC=importlib.util.spec_from_file_location('native_menu',Path(__file__).resolve().parents[1]/'tools/native-menu-resources.py')
MODULE=importlib.util.module_from_spec(SPEC);SPEC.loader.exec_module(MODULE)
def string(s):return bytes([len(s)])+s.encode('ascii')
class NativeDfmReaderTests(unittest.TestCase):
 def test_component_with_properties(self):
  b=b'TPF0'+string('TForm')+string('root')+string('Left')+bytes([3])+b'\xf0\xff'+string('Visible')+bytes([9])+bytes([0,0])
  p=MODULE.Dfm(b);n=p.node();self.assertEqual(n['properties'],{'Left':-16,'Visible':True});self.assertEqual(p.p,len(b))
 def test_bounded_string(self):
  with self.assertRaises(ValueError):MODULE.Dfm(b'TPF0\x09oops').node()
 def test_invalid_signature(self):
  with self.assertRaises(ValueError):MODULE.Dfm(b'fail')
 def test_collection_property_order(self):
  b=b'TPF0'+string('TForm')+string('root')+string('Items')+bytes([14,1])+string('Caption')+bytes([6])+string('Hello')+bytes([0,0,0,0])
  p=MODULE.Dfm(b);n=p.node();self.assertEqual(n['properties']['Items'],[{'Caption':'Hello'}]);self.assertEqual(p.p,len(b))
if __name__=='__main__':unittest.main()
