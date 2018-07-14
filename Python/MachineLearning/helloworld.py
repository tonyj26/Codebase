import tensorflow as tf

c = tf.constant('Hello, world!')

sess = tf.Session()

print(sess.run(c))

sess.close()
