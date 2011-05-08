# encoding: UTF-8

import hashlib
import sys
import getpass
import win32clipboard as CB


try:
    hash_type = sys.argv[1]
except IndexError:
    print 'Specify the hash name as the first argument.'
    print "md5 sha1 sha224 sha256 sha384 sha512"
else:
    p = getpass.getpass()
    h = hashlib.new(hash_type)
    h.update(p);
#        print h.hexdigest()

#クリップボードに文字を送ります。
    CB.OpenClipboard()
    CB.EmptyClipboard()
    CB.SetClipboardText(h.hexdigest())
    CB.CloseClipboard()
    print " copyed to Clipboard... \nComplete..."

#クリップボードから文字列を取り出します。
#CB.OpenClipboard()
#text = CB.GetClipboardData(1) #1 -> CF_TEXT
#CB.CloseClipboard()

#    print text

##クリップボードを空にします。
#CB.OpenClipboard()
#CB.EmptyClipboard()
#CB.CloseClipboard()
